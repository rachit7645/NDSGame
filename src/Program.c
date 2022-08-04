#include "Program.h"

#include <nds/interrupts.h>
#include <nds/arm9/console.h>
#include <nds/arm9/exceptions.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "Interrupts.h"
#include "Graphics.h"
#include "Input.h"
#include "Global.h"

// TODO: Replace consoleDemoInit with proper DS calls

// Variables
DSKeys        keys;
touchPosition touch;
size_t        frameCounter;

void Program_Run()
{
	// Initialise console
	defaultExceptionHandler();

	IRQ_Init();
	GFX_Init();

	consoleDemoInit();
	GFX_InitBG();

	iprintf("\x1b[0;0HSystem initialsed.");
	Program_MainLoop();
}

void Program_MainLoop()
{
	while(true)
	{
		swiWaitForVBlank();
		
		Input_Get(&keys, &touch);
		if(keys.start)
		{
			break;
		}

		iprintf("\x1b[2;0HTouch X: %4u", touch.rawx);
		iprintf("\x1b[3;0HTouch Y: %4u", touch.rawy);

		iprintf("\x1b[5;0HFrame Count: %u", frameCounter);
	}
}