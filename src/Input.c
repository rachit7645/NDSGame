#include "Input.h"

void Input_Get(DSKeys* keys, touchPosition* touch)
{
	// Scan key input
	scanKeys();
	keys->rawValue = keysDown();
	// Scan touch input
	touchRead(touch);
}