#include "Program.h"

#include <nds/interrupts.h>
#include <nds/arm9/input.h>
#include <nds/arm9/console.h>
#include <nds/arm9/decompress.h>

#include <stdio.h>
#include <stdlib.h>

#include "Interrupts.h"

#include "bg0.h"

// Variables
DSKeys        keys;
touchPosition touch;
size_t        frameCounter;

void Program_Run()
{
	// Initialise interrupts
	IRQ_Init();
	// Main screen will have 2 text and 2 background layers
	videoSetMode(MODE_5_2D);
	// Sub screen will be used for text
	videoSetModeSub(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	// Init program
	consoleDemoInit();
	// Set up bitmap background
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(bg0Bitmap, BG_GFX,  LZ77Vram);
	iprintf("\x1b[0;0HSystem initialsed.");
	// Call main loop
	Program_MainLoop();
}

void Program_MainLoop()
{
	while(true)
	{
		// Wait for vertical balnk
		swiWaitForVBlank();
		// Scan keys
		scanKeys();
		keys.rawValue = keysDown();
		
		// If the start key is pressed, return
		if(keys.start)
		{
			break;
		}

		// Touch handler 
		touchRead(&touch);
		iprintf("\x1b[2;0HTouch X: %4u", touch.rawx);
		iprintf("\x1b[3;0HTouch Y: %4u", touch.rawy);

		iprintf("\x1b[5;0HFrame Count: %u", frameCounter);
	}
}