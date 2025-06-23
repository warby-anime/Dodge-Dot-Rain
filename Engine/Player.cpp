#include "Player.h"


void Player::Draw ( Graphics& gfx ) const
{
	gfx.DrawRectDim ( x , y , width , height , c );
}

void Player::PaddleMove ( Keyboard& kbd )
{
	if ( kbd.KeyIsPressed ( VK_RIGHT ) )
	{
		x += speed;
	}
	else if ( kbd.KeyIsPressed ( VK_LEFT ) )
	{
		x += -speed;
	}
}

void Player::ClampToScreen () 
{
	
	if ( x <= 0 )
	{
		 x = 1;
	}
	const int right = x + width;
	if ( right >= Graphics::ScreenWidth )
	{
		 x = ( Graphics::ScreenWidth - 1 ) -width;
	}
	
}


