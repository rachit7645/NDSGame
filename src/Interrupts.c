#include "Interrupts.h"

#include <nds/interrupts.h>

#include "Program.h"

void IRQ_Init()
{
	irqSet(IRQ_VBLANK, IRQ_VBlank);
}

void IRQ_VBlank()
{
	++frameCounter;
}