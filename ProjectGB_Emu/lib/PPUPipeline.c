#include <PPU.h>
#include <LCD.h>
#include <Bus.h>

void PixelFIFOPush(u32 value) {
    fifoEntry *next = malloc(sizeof(fifoEntry));
    next->next = NULL;
    next->value = value;

    if (!GetPPUContext()->pfc.pixelFIFO.head) {
        //first entry...
        GetPPUContext()->pfc.pixelFIFO.head = GetPPUContext()->pfc.pixelFIFO.tail = next;
    } else {
        GetPPUContext()->pfc.pixelFIFO.tail->next = next;
        GetPPUContext()->pfc.pixelFIFO.tail = next;
    }

    GetPPUContext()->pfc.pixelFIFO.size++;
}

u32 PixelFIFOPop() {
    if (GetPPUContext()->pfc.pixelFIFO.size <= 0) {
        fprintf(stderr, "ERR IN PIXEL FIFO!\n");
        exit(-8);
    }

    fifoEntry *popped = GetPPUContext()->pfc.pixelFIFO.head;
    GetPPUContext()->pfc.pixelFIFO.head = popped->next;
    GetPPUContext()->pfc.pixelFIFO.size--;

    u32 val = popped->value;
    free(popped);

    return val;
}

bool PipelineFIFOAdd() {
    if (GetPPUContext()->pfc.pixelFIFO.size > 8) {
        //fifo is full!
        return false;
    }

    int x = GetPPUContext()->pfc.fetchX - (8 - (GetLCDContext()->scrollX % 8));

    for (int i=0; i<8; i++) {
        int bit = 7 - i;
        u8 hi = !!(GetPPUContext()->pfc.backgroundFetchData[1] & (1 << bit));
        u8 lo = !!(GetPPUContext()->pfc.backgroundFetchData[2] & (1 << bit)) << 1;
        u32 color = GetLCDContext()->bgColors[hi | lo];

        if (x >= 0) {
            PixelFIFOPush(color);
            GetPPUContext()->pfc.fifoX++;
        }
    }

    return true;
}

void PipelineFetch() {
    switch(GetPPUContext()->pfc.currentState) {
        case FS_TILE: {
            if (LCDC_BGW_ENABLE) {
                GetPPUContext()->pfc.backgroundFetchData[0] = ReadBus(LCDC_BG_MAP_AREA + 
                    (GetPPUContext()->pfc.mapX / 8) + 
                    (((GetPPUContext()->pfc.mapY / 8)) * 32));
            
                if (LCDC_BGW_DATA_AREA == 0x8800) {
                    GetPPUContext()->pfc.backgroundFetchData[0] += 128;
                }
            }

            GetPPUContext()->pfc.currentState = FS_DATA0;
            GetPPUContext()->pfc.fetchX += 8;
        } break;

        case FS_DATA0: {
            GetPPUContext()->pfc.backgroundFetchData[1] = ReadBus(LCDC_BGW_DATA_AREA +
                (GetPPUContext()->pfc.backgroundFetchData[0] * 16) + 
                GetPPUContext()->pfc.tileY);

            GetPPUContext()->pfc.currentState = FS_DATA1;
        } break;

        case FS_DATA1: {
            GetPPUContext()->pfc.backgroundFetchData[2] = ReadBus(LCDC_BGW_DATA_AREA +
                (GetPPUContext()->pfc.backgroundFetchData[0] * 16) + 
                GetPPUContext()->pfc.tileY + 1);

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

void PipelinePushPixel() {
    if (GetPPUContext()->pfc.pixelFIFO.size > 8) {
        u32 pixel_data = PixelFIFOPop();

        if (GetPPUContext()->pfc.lineX >= (GetLCDContext()->scrollX % 8)) {
            GetPPUContext()->vidBuffer[GetPPUContext()->pfc.pushedX + 
                (GetLCDContext()->ly * XRES)] = pixel_data;

            GetPPUContext()->pfc.pushedX++;
        }

        GetPPUContext()->pfc.lineX++;
    }
}

void PipelineProcess() {
    GetPPUContext()->pfc.mapY = (GetLCDContext()->ly + GetLCDContext()->scrollY);
    GetPPUContext()->pfc.mapX = (GetPPUContext()->pfc.fetchX + GetLCDContext()->scrollX);
    GetPPUContext()->pfc.tileY = ((GetLCDContext()->ly + GetLCDContext()->scrollY) % 8) * 2;

    if (!(GetPPUContext()->lineTicks & 1)) {
        PipelineFetch();
    }

    PipelinePushPixel();
}

void PipelineFIFOReset() {
    while(GetPPUContext()->pfc.pixelFIFO.size) {
        PixelFIFOPop();
    }

    GetPPUContext()->pfc.pixelFIFO.head = 0;
}