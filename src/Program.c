#include "Program.h"

#include <nds/dma.h>
#include <nds/interrupts.h>
#include <nds/arm9/console.h>
#include <nds/arm9/exceptions.h>
#include <nds/arm9/decompress.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "Interrupts.h"
#include "Graphics.h"
#include "Input.h"
#include "Global.h"
#include "Sprite.h"
#include "Macros.h"

// Global variables
size_t frameCounter = 0;

// Other variables
DSKeys        keys;
touchPosition touch;
Sprite        sprites[NUM_SPRITES];

void Program_Run()
{
	// Initialise console
	defaultExceptionHandler();

	Program_InitData();
	IRQ_Init();
	GFX_Init();

	consoleDemoInit();
	
	GFX_InitBG();
	GFX_InitSprites(NUM_SPRITES, sprites);

	iprintf("\x1b[0;0HSystem initialsed.");
	Program_MainLoop();
	
	GFX_FreeMemory(NUM_SPRITES, sprites);
}

void Program_MainLoop()
{
	while(true)
	{
		GFX_UpdateSprites(NUM_SPRITES, sprites);

		swiWaitForVBlank();

		Input_Get(&keys, &touch);
		if(keys.start)
		{
			break;
		}

		iprintf("\x1b[2;0HTouch X: %4u", touch.rawx);
		iprintf("\x1b[3;0HTouch Y: %4u", touch.rawy);

		iprintf("\x1b[5;0HFrame Count:    %u", frameCounter);
		iprintf("\x1b[6;0HRotation Angle: %u", spriteAngle);

		GFX_Update();
	}
}

void Program_InitData()
{
	for (int i = 0; i < NUM_SPRITES; ++i)
	{
		sprites[i].gfx           = 0;
		sprites[i].size          = SpriteSize_32x32;
		sprites[i].format        = SpriteColorFormat_Bmp;
		sprites[i].rotationIndex = 0;
		sprites[i].paletteAlpha  = 15;
		sprites[i].x             = 20;
		sprites[i].y             = 20 * i;
	}
}