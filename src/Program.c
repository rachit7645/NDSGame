#include "Program.h"

#include <nds.h>
#include <nds/arm9/input.h>
#include <nds/arm9/console.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Variables
DSKeys        keys;
touchPosition touch;

void Program_Run()
{
	// Init program
	consoleDemoInit();
	iprintf("System initialsed.");
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

		touchRead(&touch);
		iprintf("\x1b[3;0HTouch X: %4u", touch.rawx);
		iprintf("\x1b[4;0HTouch Y: %4u", touch.rawy);
	}
}