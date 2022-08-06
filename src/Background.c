#include "Background.h"

#include <nds/arm9/sassert.h>

#include <stddef.h>

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
)
{
	sassert(background != NULL, "Null Check Failed");

	background->scrollX  = scrollX;
	background->scrollY  = scrollY;
	background->layer    = layer;
	background->type     = type;
	background->size     = size;
	background->mapBase  = mapBase;
	background->tileBase = tileBase;
	background->id       = bgInit(layer, type, size, mapBase, tileBase);
}