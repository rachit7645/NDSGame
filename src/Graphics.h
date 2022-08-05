#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <nds/ndstypes.h>

#include <stddef.h>

#include "Sprite.h"

// Initialise graphics
void GFX_Init();
// Initialise background
void GFX_InitBG();
// Initialise sprites
void GFX_InitSprites(int count, Sprite* sprites);
// Update graphics
void GFX_Update();
// Update sprites
void GFX_UpdateSprites(int count, Sprite* sprites);
// Free memory
void GFX_FreeMemory(int count, Sprite* sprites);

#endif