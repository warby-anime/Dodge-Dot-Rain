#pragma once
#include "Graphics.h"
#include <random>

class Rain
{
public:
	Rain ( std::mt19937& rng );
	void Draw ( Graphics& gfx );
	void Speed ();
	void Respawn ( std::mt19937& rng );
private:
	int x = 400;
	int y = 60;
	int r = 5;
	Color c = Colors::Red;
	int speed = 1;
	
};

