#ifndef SPRITE_H
#define SPRITE_H

#include <nds/ndstypes.h>
#include <nds/arm9/sprite.h>

#define NUM_SPRITES 1

typedef struct _Sprite
{
	u16*              gfx;
	SpriteSize        size;
	SpriteColorFormat format;
	int               rotationIndex;
	int               paletteAlpha;
	int               x;
	int               y;
} Sprite;

void Sprite_Create
(
	Sprite* sprite,
	SpriteSize size,
	SpriteColorFormat format,
	int rotationIndex,
	int paletteAlpha,
	int x,
	int y
);

#endif