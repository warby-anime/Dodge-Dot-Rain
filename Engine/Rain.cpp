#include "Rain.h"


void Rain::Init ( std::mt19937& rng )
{
	std::uniform_int_distribution<int>xDist ( 10 , 770 );
	x = xDist ( rng );
}

void Rain::Draw ( Graphics& gfx )
{
	gfx.DrawCircle ( x , y , r , c );
}

void Rain::Speed ()
{
	y += speed;
}

int Rain::GetY ()
{
	return y;
}

void Rain::Respawn ( std::mt19937& rng )
{
	std::uniform_int_distribution<int>xDist ( 1 , 790 );
	do
	{

		x = xDist ( rng );
		y = 60;
		
	} while ( y >= Graphics::ScreenHeight - 10 );
}


