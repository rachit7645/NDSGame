#include "Input.h"

#include <nds/arm9/sassert.h>

#include <stddef.h>

void Input_Get(DSKeys* keys, touchPosition* touch)
{
	sassert(keys != NULL && touch != NULL, "Null Check Failed");

	// Scan key input
	scanKeys();
	keys->rawValue = keysHeld();
	// Scan touch input
	touchRead(touch);
}