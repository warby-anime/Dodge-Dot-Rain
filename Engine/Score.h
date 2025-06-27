#pragma once
#include "Graphics.h"

class Score
{
public:
	void Draws ( Graphics& gfx );
	int Increase ();

private:
	static constexpr int x = 0;
	static constexpr int y = 11;
	int width = 0;
	static constexpr int height = 10;
	Color c = Colors::Blue;

};

