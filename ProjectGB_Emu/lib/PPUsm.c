#include <PPU.h>
#include <LCD.h>
#include <CPU.h>
#include <Interrupts.h>
#include <LCD.h>
#include <string.h>
#include <Cartridge.h>

void PipelineFIFOReset(); //declaring functions for PPUPipeline.c
void PipelineProcess();
bool WindowVisible();

//PPU State Machine

void  IncrementLY()
{
    if (WindowVisible() && GetLCDContext()->ly >= GetLCDContext()->winY &&
        GetLCDContext()->ly < GetLCDContext()->winY + YRES)
        {
            GetPPUContext()->windowLine++;
        }

    GetLCDContext()->ly++;

    if (GetLCDContext()->ly == GetLCDContext()->lyCompare) //if the ly and lyCompare value are the same
    {
        LCDS_LYC_SET(1); //set ly to 1

        if (LCDS_STAT_INT(SS_LYC))
        {
            RequestCPUInterrupts(IT_LCD_STAT);
        }
    }
    else
    {
        LCDS_LYC_SET(0);
    }
}

void LoadLineSprites()
{
    int curY = GetLCDContext()->ly;

    u8 spriteHeight = LCDC_OBJ_HEIGHT;
    memset(GetPPUContext()->lineEntryArray, 0, sizeof(GetPPUContext()->lineEntryArray));

    for (int i = 0; i < 40; i++)
    {
        OAMEntry e = GetPPUContext()->oamRam[i];

        if (!e.x) //if x = 0, it means the sprite is not visible
        {
            continue;
        }

        if (GetPPUContext()->lineSpriteCount >= 10) //max 10 sprites per line
        {
            break;
        }

        if (e.y <= curY + 16 && e.y + spriteHeight > curY + 16) //if the sprite is on the current line
        {
            OAMLineEntry *entry = &GetPPUContext()->lineEntryArray[GetPPUContext()->lineSpriteCount++];

            entry->entry = e;
            entry->next = NULL;

            if (!GetPPUContext()->lineSprites || GetPPUContext()->lineSprites->entry.x > e.x)
            {
                entry->next = GetPPUContext()->lineSprites;
                GetPPUContext()->lineSprites = entry;
                continue;
            }

            //sorting sprites..
            OAMLineEntry *le = GetPPUContext()->lineSprites;
            OAMLineEntry *prev = le;

            while(le)
            {
                if (le->entry.x > e.x)
                {
                    prev->next = entry;
                    entry->next = le;
                    break;
                }

                if (!le->next)
                {
                    le->next = entry;
                    break;
                }

                prev = le;
                le = le->next;
            }
        }
    }
}

void PPUModeOAM()
{
    if (GetPPUContext()->lineTicks >= 80) //when line ticks are greater than 80, we switch to the next mode (XFER)
    {
        LCDS_MODE_SET(MODE_XFER);

        GetPPUContext()->pfc.currentState = FS_TILE;
        GetPPUContext()->pfc.lineX = 0; 
        GetPPUContext()->pfc.fetchX = 0;
        GetPPUContext()->pfc.pushedX = 0;
        GetPPUContext()->pfc.fifoX = 0;

    }

    if (GetPPUContext()->lineTicks == 1) //if linetick = 1, we will read all OAM on that first tick
    {
        GetPPUContext()->lineSprites = 0;
        GetPPUContext()->lineSpriteCount = 0;

        LoadLineSprites();
    }
}

void PPUModeXFER()
{
    PipelineProcess();

    if (GetPPUContext()->pfc.pushedX >= XRES) //switch to HBLANK mode when these conditions are met
    {
        PipelineFIFOReset();
        LCDS_MODE_SET(MODE_HBLANK);

        if (LCDS_STAT_INT(SS_HBLANK))
        {
            RequestCPUInterrupts(IT_LCD_STAT);
        }
    }    
}

void PPUModeVBLANK()
{
   if (GetPPUContext()->lineTicks >= TICKS_PER_LINE)
   {
        IncrementLY();

        if (GetLCDContext()->ly >= LINES_PER_FRAME)
        {
            LCDS_MODE_SET(MODE_OAM);
            GetLCDContext()->ly = 0;
            GetPPUContext()->windowLine = 0;
        }

        GetPPUContext()->lineTicks = 0;
   } 
}

static u32 targetFrameTime = 1000 / 60; //this will set the target FPS to 60
static long prevFrameTime = 0;
static long startTimer = 0;
static long frameCount = 0;

void PPUModeHBLANK()
{
    if (GetPPUContext()->lineTicks >= TICKS_PER_LINE)
    {
        IncrementLY();


        if (GetLCDContext()->ly >= YRES)
        {
            LCDS_MODE_SET(MODE_VBLANK);

            RequestCPUInterrupts(IT_VBLANK);

            if (LCDS_STAT_INT(SS_VBLANK))
            {
                RequestCPUInterrupts(IT_LCD_STAT);
            }

            GetPPUContext()->currentFrame++;

            //calulate FPS...
            u32 end = getTicks();
            u32 frameTime = end - prevFrameTime; //amount of time taken between frames

            if (frameTime < targetFrameTime) //if frame time is less than our target
            {
                delay((targetFrameTime - frameTime)); //we delay in the amount of ms from targetFrameTime - frameTime to get 60 FPS
            }

            if (end - startTimer >= 1000) //if this is true, we are on the next second
            {
                u32 FPS = frameCount;

                startTimer = end;
                frameCount = 0;

                printf("FPS: %d\n", FPS); //print out the FPS

                if (CartridgeNeedSave())
                {
                    CartridgeBatterySave();
                }
            }

            frameCount++;
            prevFrameTime = getTicks();
        }
        else
        {
            LCDS_MODE_SET(MODE_OAM);
        }

        GetPPUContext()->lineTicks = 0;
    }
}

