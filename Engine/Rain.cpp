#include "Rain.h"

Rain::Rain ( std::mt19937& rng )
{
	Respawn ( rng );
}

void Rain::Draw ( Graphics& gfx )
{
	gfx.DrawCircle ( x , y , r , c );
}

void Rain::Speed ()
{
	y += speed;
}

void Rain::Respawn ( std::mt19937& rng )
{
	std::uniform_int_distribution <int> xDist ( 1 , Graphics::ScreenWidth - 1 );
	
	int newX;
	int newY;
		do
		{
			newX = xDist ( rng );
			newY = 60;
		} while ( y + r == ( Graphics::ScreenHeight - 5 ) );

		x = newX;
		y = newY;
	
}
