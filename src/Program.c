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
#include "Player.h"
#include "Background.h"

// Global variables
size_t        frameCounter = 0;
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

	iprintf(TEXT_FMT(0, 0, "System initialsed."));
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
		
		if (keys.start)
		{
			break;
		}

		Player_Update();

		iprintf(TEXT_FMT(2, 0, "Touch X: %4u"), touch.rawx);
		iprintf(TEXT_FMT(3, 0, "Touch Y: %4u"), touch.rawy);

		iprintf(TEXT_FMT(5, 0, "Sprite X: %4d"), sprites[0].x);
		iprintf(TEXT_FMT(6, 0, "Sprite Y: %4d"), sprites[0].y);

		iprintf(TEXT_FMT(8, 0, "Frame Count:    %u"), frameCounter);
		iprintf(TEXT_FMT(9, 0, "Rotation Angle: %u"), spriteAngle);

		GFX_Update();
	}
}

void Program_InitData()
{
	Sprite_Create
	(
		&sprites[0],           // Sprite
		SpriteSize_32x32,      // Size
		SpriteColorFormat_Bmp, // Color Format
		0,                     // Rotation Index
		15,                    // Palette / Alpha
		0,                     // X
		20                     // Y
	);
}