#include "Program.h"

#include <nds.h>
#include <nds/arm9/input.h>
#include <nds/arm9/console.h>

#include <stdio.h>
#include <stdlib.h>

// Variables
DSKeys        keys;
touchPosition touch;
size_t        frames;

void Program_Run()
{
	// Init program
	consoleDemoInit();
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
		
		frames++;
		iprintf("\x1b[5;0HFrame Count: %u", frames);
	}
}