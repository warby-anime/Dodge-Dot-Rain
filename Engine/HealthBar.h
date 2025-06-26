#pragma once
#include "Graphics.h"

class HealthBar
{
public:
	void Draw ( Graphics& gfx );
	int DamageTaken () ;

private:
	static constexpr int x = 0;
	static constexpr int y = 0;
	int width = 800;
	static constexpr int height = 10;
	Color c = Colors::Red;

};

