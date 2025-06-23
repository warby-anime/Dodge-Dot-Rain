#include "Player.h"


void Player::Draw (Graphics& gfx) const
{
	gfx.DrawRectDim (x, y, width, height, c);
}

void Player::PaddleMove (Keyboard& kbd)
{
	speed += x;
	
	if (kbd.KeyIsPressed (VK_RIGHT))
	{
		speed += 1;
	}
	else if (kbd.KeyIsPressed (VK_LEFT))
	{
		speed += -1;
	}
}
