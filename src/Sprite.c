#include "Sprite.h"

#include <nds/arm9/sassert.h>

#include <stddef.h>

void Sprite_Create
(
	Sprite* sprite,
	SpriteSize size,
	SpriteColorFormat format,
	int rotationIndex,
	int paletteAlpha,
	int x,
	int y
)
{
	sassert(sprite != NULL, "Null Check Failed");

	sprite->gfx           = 0;
	sprite->size          = size;
	sprite->format        = format;
	sprite->rotationIndex = rotationIndex;
	sprite->paletteAlpha  = paletteAlpha;
	sprite->x             = x;
	sprite->y             = y;
}