#ifndef GLOBAL_H
#define GLOBAL_H

#include <nds/arm9/input.h>

#include <stddef.h>

#include "Sprite.h"
#include "Input.h"
#include "Background.h"

extern size_t        frameCounter;
extern int           spriteAngle;
extern DSKeys        keys;
extern touchPosition touch;
extern Sprite        sprites[NUM_SPRITES];
extern Background    background;

#endif