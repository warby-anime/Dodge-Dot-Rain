#pragma once
#include "Graphics.h"
#include <random>

class Rain
{
public:
	Rain () = default;
	void Init ( std::mt19937& rng );
	void Draw ( Graphics& gfx );
	void Speed ();
	int SpeedIncrease ();
	int GetX () const;
	int GetY () const;
	int GetR () const;
	void Respawn ( std::mt19937& rng );
private:
	std::uniform_int_distribution<int>xDist;
	int x = 400;
	int y = 60;
	int r = 5;
	Color c = Colors::Cyan;
	int speed = 1;
	
	
};

