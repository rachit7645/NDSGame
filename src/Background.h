#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <nds/arm9/background.h>

typedef struct _Background
{
	int    id;
	int    scrollX;
	int    scrollY;
	int    layer;
	BgType type;
	BgSize size;
	int    mapBase;
	int    tileBase;
} Background;

void Background_Create
(
	Background* background,
	int scrollX,
	int scrollY,
	int layer,
	BgType type,
	BgSize size,
	int mapBase,
	int tileBase
);

#endif