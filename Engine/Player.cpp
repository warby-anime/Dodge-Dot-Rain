#include "Player.h"


void Player::Draw (Graphics& gfx) const
{
	gfx.DrawRectDim (x, y, width, height, c);
}

void Player::PaddleMove (Keyboard& kbd)
{
	if (kbd.KeyIsPressed (VK_RIGHT))
	{
		x += speed;
	}
	else if (kbd.KeyIsPressed (VK_LEFT))
	{
		x += -speed;
	}
}


