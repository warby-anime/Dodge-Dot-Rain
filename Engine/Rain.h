#pragma once
#include "Graphics.h"

class Rain
{
public:
	void Draw (Graphics& gfx);
private:
	int x = 400;
	int y = 60;
	int r = 5;
	Color c = Colors::Red;
};

