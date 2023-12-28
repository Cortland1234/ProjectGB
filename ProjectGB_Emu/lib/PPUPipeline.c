#include <PPU.h>
#include <LCD.h>
#include <Bus.h>

bool WindowVisible() //checking to see if the window is enabled and visible
{
    return LCDC_WIN_ENABLE && GetLCDContext()->winX >= 0 && GetLCDContext()->winX <= 166 &&
    GetLCDContext()->winY >= 0 && GetLCDContext()->winY < YRES;
}

void PixelFIFOPush(u32 value) //pushes a pixel to the FIFO
{
    fifoEntry *next = malloc(sizeof(fifoEntry)); //allocating memory for the fifoentry pointer
    next->next = NULL;
    next->value = value;

    if (!GetPPUContext()->pfc.pixelFIFO.head) { //if the pixelFIFO head is not set
        //first entry...
        GetPPUContext()->pfc.pixelFIFO.head = GetPPUContext()->pfc.pixelFIFO.tail = next;
    } else {
        GetPPUContext()->pfc.pixelFIFO.tail->next = next;
        GetPPUContext()->pfc.pixelFIFO.tail = next;
    }

    GetPPUContext()->pfc.pixelFIFO.size++;
}

u32 PixelFIFOPop() 
{
    if (GetPPUContext()->pfc.pixelFIFO.size <= 0) { //if the size of the FIFO is empty at time of pop call
        fprintf(stderr, "ERR IN PIXEL FIFO!\n");
        exit(-8);
    }

    fifoEntry *popped = GetPPUContext()->pfc.pixelFIFO.head; //value to be popped is the head of the FIFO
    GetPPUContext()->pfc.pixelFIFO.head = popped->next; //popping value from FIFO
    GetPPUContext()->pfc.pixelFIFO.size--; //decrementing size of linked list

    u32 val = popped->value; //grabbing value of popped so function can return it
    free(popped); //freeing the memory popped took up again

    return val;
}

u32 FetchSpritePixels(int bit, u32 color, u8 bg_color) 
{
    for (int i=0; i<GetPPUContext()->fetchEntryCount; i++) {
        int sp_x = (GetPPUContext()->fetchEntries[i].x - 8) + 
            ((GetLCDContext()->scrollX % 8));
        
        if (sp_x + 8 < GetPPUContext()->pfc.fifoX) {
            //past pixel point already...
            continue;
        }

        int offset = GetPPUContext()->pfc.fifoX - sp_x;

        if (offset < 0 || offset > 7) {
            //out of bounds..
            continue;
        }

        bit = (7 - offset);

        if (GetPPUContext()->fetchEntries[i].xFlipFlag) {
            bit = offset;
        }

        u8 hi = !!(GetPPUContext()->pfc.fetchEntryData[i * 2] & (1 << bit));
        u8 lo = !!(GetPPUContext()->pfc.fetchEntryData[(i * 2) + 1] & (1 << bit)) << 1;

        bool bg_priority = GetPPUContext()->fetchEntries[i].bgPriorityFlag;

        if (!(hi|lo)) {
            //transparent
            continue;
        }

        if (!bg_priority || bg_color == 0) {
            color = (GetPPUContext()->fetchEntries[i].paletteNumFlag) ? 
                GetLCDContext()->spriteColors2[hi|lo] : GetLCDContext()->spriteColors1[hi|lo];

            if (hi|lo) {
                break;
            }
        }
    }

    return color;
}

bool PipelineFIFOAdd() 
{
    if (GetPPUContext()->pfc.pixelFIFO.size > 8) { //if FIFO is full
        //fifo is full!
        return false;
    }

    int x = GetPPUContext()->pfc.fetchX - (8 - (GetLCDContext()->scrollX % 8));

    for (int i=0; i<8; i++) {
        int bit = 7 - i;
        u8 hi = !!(GetPPUContext()->pfc.backgroundFetchData[1] & (1 << bit));
        u8 lo = !!(GetPPUContext()->pfc.backgroundFetchData[2] & (1 << bit)) << 1;
        u32 color = GetLCDContext()->bgColors[hi | lo];

        if (!LCDC_BGW_ENABLE) {
            color = GetLCDContext()->bgColors[0];
        }

        if (LCDC_OBJ_ENABLE) {
            color = FetchSpritePixels(bit, color, hi | lo);
        }

        if (x >= 0) {
            PixelFIFOPush(color);
            GetPPUContext()->pfc.fifoX++;
        }
    }

    return true;
}

void PipelineLoadSpriteTile() 
{
    OAMLineEntry *le = GetPPUContext()->lineSprites;

    while(le) {
        int sp_x = (le->entry.x - 8) + (GetLCDContext()->scrollX % 8);

        if ((sp_x >= GetPPUContext()->pfc.fetchX && sp_x < GetPPUContext()->pfc.fetchX + 8) ||
            ((sp_x + 8) >= GetPPUContext()->pfc.fetchX && (sp_x + 8) < GetPPUContext()->pfc.fetchX + 8)) {
            //need to add entry
            GetPPUContext()->fetchEntries[GetPPUContext()->fetchEntryCount++] = le->entry;
        }

        le = le->next;

        if (!le || GetPPUContext()->fetchEntryCount >= 3) {
            //max checking 3 sprites on pixels
            break;
        }
    }
}

void PipelineLoadPixelData(u8 offset) 
{
    int cur_y = GetLCDContext()->ly;
    u8 sprite_height = LCDC_OBJ_HEIGHT;

    for (int i=0; i<GetPPUContext()->fetchEntryCount; i++) {
        u8 ty = ((cur_y + 16) - GetPPUContext()->fetchEntries[i].y) * 2;

        if (GetPPUContext()->fetchEntries[i].yFlipFlag) {
            //flipped upside down...
            ty = ((sprite_height * 2) - 2) - ty;
        }

        u8 tile_index = GetPPUContext()->fetchEntries[i].tile;

        if (sprite_height == 16) {
            tile_index &= ~(1); //remove last bit...
        }

        GetPPUContext()->pfc.fetchEntryData[(i * 2) + offset] = 
            ReadBus(0x8000 + (tile_index * 16) + ty + offset);
    }
}


void PipelineLoadWindowTile()
{
    if (!WindowVisible())
    {
        return;
    }
    u8 windowY = GetLCDContext()->winY;
    
    if (GetPPUContext()->pfc.fetchX + 7 >= GetLCDContext()->winX &&
        GetPPUContext()->pfc.fetchX + 7 < GetLCDContext()->winX + YRES + 14)
        {
            if (GetLCDContext()->ly >= windowY && GetLCDContext()->ly < windowY + XRES)
            {
                u8 winTileY = GetPPUContext()->windowLine / 8;

                GetPPUContext()->pfc.backgroundFetchData[0] = ReadBus(LCDC_WIN_MAP_AREA +
                ((GetPPUContext()->pfc.fetchX + 7 - GetLCDContext()->winX) / 8) + (winTileY * 32));

                if (LCDC_BGW_DATA_AREA == 0x8800)
                {
                    GetPPUContext()->pfc.backgroundFetchData[0] += 128;
                }
            }
        }
}

void PipelineFetch() 
{
    switch(GetPPUContext()->pfc.currentState) {
        case FS_TILE: {
            GetPPUContext()->fetchEntryCount = 0;

            if (LCDC_BGW_ENABLE) {
                GetPPUContext()->pfc.backgroundFetchData[0] = ReadBus(LCDC_BG_MAP_AREA + 
                    (GetPPUContext()->pfc.mapX / 8) + 
                    (((GetPPUContext()->pfc.mapY / 8)) * 32));
            
                if (LCDC_BGW_DATA_AREA == 0x8800) {
                    GetPPUContext()->pfc.backgroundFetchData[0] += 128;
                }

                PipelineLoadWindowTile();
            }

            if (LCDC_OBJ_ENABLE && GetPPUContext()->lineSprites) {
                PipelineLoadSpriteTile();
            }

            GetPPUContext()->pfc.currentState = FS_DATA0;
            GetPPUContext()->pfc.fetchX += 8;
        } break;

        case FS_DATA0: {
            GetPPUContext()->pfc.backgroundFetchData[1] = ReadBus(LCDC_BGW_DATA_AREA +
                (GetPPUContext()->pfc.backgroundFetchData[0] * 16) + 
                GetPPUContext()->pfc.tileY);

            PipelineLoadPixelData(0);

            GetPPUContext()->pfc.currentState = FS_DATA1;
        } break;

        case FS_DATA1: {
            GetPPUContext()->pfc.backgroundFetchData[2] = ReadBus(LCDC_BGW_DATA_AREA +
                (GetPPUContext()->pfc.backgroundFetchData[0] * 16) + 
                GetPPUContext()->pfc.tileY + 1);

            PipelineLoadPixelData(1);

            GetPPUContext()->pfc.currentState = FS_IDLE;

        } break;

        case FS_IDLE: {
            GetPPUContext()->pfc.currentState = FS_PUSH;
        } break;

        case FS_PUSH: {
            if (PipelineFIFOAdd()) {
                GetPPUContext()->pfc.currentState = FS_TILE;
            }

        } break;

    }
}

void PipelinePushPixel() //pushes pixels onto the pipeline
{
    if (GetPPUContext()->pfc.pixelFIFO.size > 8) { //if the FIFO is full
        u32 pixel_data = PixelFIFOPop(); //pop a pixel value to make room in FIFO

        if (GetPPUContext()->pfc.lineX >= (GetLCDContext()->scrollX % 8)) {
            GetPPUContext()->vidBuffer[GetPPUContext()->pfc.pushedX + 
                (GetLCDContext()->ly * XRES)] = pixel_data;

            GetPPUContext()->pfc.pushedX++;
        }

        GetPPUContext()->pfc.lineX++;
    }
}

void PipelineProcess() 
{
    GetPPUContext()->pfc.mapY = (GetLCDContext()->ly + GetLCDContext()->scrollY);
    GetPPUContext()->pfc.mapX = (GetPPUContext()->pfc.fetchX + GetLCDContext()->scrollX);
    GetPPUContext()->pfc.tileY = ((GetLCDContext()->ly + GetLCDContext()->scrollY) % 8) * 2;

    if (!(GetPPUContext()->lineTicks & 1)) { //if the first bit of lineticks is not set, the line is even
        PipelineFetch(); //fetched every other line
    }

    PipelinePushPixel();//called every line
}

void PipelineFIFOReset()
{
    while(GetPPUContext()->pfc.pixelFIFO.size) {
        PixelFIFOPop();
    }

    GetPPUContext()->pfc.pixelFIFO.head = 0;
}