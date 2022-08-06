#include "Player.h"

#define PLAYER       sprites[0]
// Player attributes
#define PLAYER_SPEED 4

void Player_Update()
{
	Player_CheckInputs();
}

void Player_CheckInputs()
{
	if (keys.up)
	{
		PLAYER.y -= PLAYER_SPEED;
	}
	else if (keys.down)
	{
		PLAYER.y += PLAYER_SPEED;
	}

	if (keys.left)
	{
		PLAYER.x -= PLAYER_SPEED;
	}
	else if (keys.right)
	{
		PLAYER.x += PLAYER_SPEED;
	}
}