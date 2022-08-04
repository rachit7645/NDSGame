#include "Graphics.h"

#include <nds/arm9/decompress.h>
#include <nds/arm9/console.h>

#include "bg0.h"

void GFX_Init()
{
	// Main screen will have 2 text and 2 background layers
	videoSetMode(MODE_5_2D);
	// Sub screen will be used for text
	videoSetModeSub(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
}

void GFX_InitBG()
{
	// Set up bitmap background
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	decompress(bg0Bitmap, BG_GFX, LZ77Vram);
}