#include "Background.h"

#include <nds/arm9/sassert.h>

#include <stddef.h>

NDS_STATIC NDS_INLINE int Background_InitGFX(Background* background)
{
	return bgInit
	(
		background->layer,
		background->type,
		background->size,
		background->mapBase,
		background->tileBase
	);
}

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
	background->id       = Background_InitGFX(background);
}