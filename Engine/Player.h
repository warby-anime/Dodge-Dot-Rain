#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Player
{
public:
	void Draw (Graphics& gfx ) const;
	void PaddleMove (Keyboard& kbd );

private:
	int x = 400;
	int y = 500;
	static constexpr int width = 30;
	static constexpr int height = 20;
	Color c = Colors::Gray;
	int speed = 0;
};

