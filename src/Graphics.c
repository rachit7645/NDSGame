#include "Graphics.h"

#include <nds/arm9/decompress.h>
#include <nds/arm9/console.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/sassert.h>

#include <stdbool.h>
#include <stddef.h>

#include "Global.h"

#include "bg0.h"
#include "spr0.h"

// Global variables
int        spriteAngle = 0;
Background background;

void GFX_Init()
{
	// Main screen will have 2 text and 2 background layers
	videoSetMode(MODE_5_2D);
	// Sub screen will be used for text
	videoSetModeSub(MODE_0_2D);
	// Set vram banks
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_SPRITE);
}

void GFX_InitBG()
{
	// Set up bitmap background
	Background_Create
	(
		&background,
		0,
		0,
		3,
		BgType_Bmp16,
		BgSize_B16_256x256,
		0, 
		0
	);
	decompress(bg0Bitmap, BG_GFX, LZ77Vram);
}

void GFX_InitSprites(int count, Sprite* sprites)
{
	sassert(count > 0 && sprites != NULL, "Null Check Failed");

	oamInit(&oamMain, SpriteMapping_1D_128, false);

	for (int i = 0; i < count; ++i)
	{
		sprites[i].gfx = oamAllocateGfx(&oamMain, sprites[i].size, sprites[i].format);
	}

	// Set up sprite one
	decompress(spr0Bitmap, sprites[0].gfx, LZ77Vram);
}

void GFX_UpdateSprites(int count, Sprite* sprites)
{
	sassert(count > 0 && sprites != NULL, "Null Check Failed");

	for (int i = 0; i < count; ++i)
	{
		oamSet
		(
			&oamMain,
			i,                        // ID
			sprites[i].x,
			sprites[i].y,
			0,                        // Priority
			sprites[i].paletteAlpha,
			sprites[i].size,
			sprites[i].format,
			sprites[i].gfx,
			sprites[i].rotationIndex,
			true,                     // Size Double
			false,                    // Hide
			false,                    // VFlip
			false,                    // HFlip
			false                     // Mosaic
		);
	}

	oamRotateScale(&oamMain, 0, spriteAngle, (1 << 8), (1 << 8));
	spriteAngle += 64;
}

void GFX_FreeMemory(int count, Sprite* sprites)
{
	sassert(count > 0 && sprites != NULL, "Null Check Failed");

	for (int i = 0; i < count; ++i)
	{
		oamFreeGfx(&oamMain, sprites[i].gfx);
	}
}

void GFX_Update()
{
	bgUpdate();
	oamUpdate(&oamMain);
}