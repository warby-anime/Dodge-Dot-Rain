#include "Score.h"

void Score::Draws ( Graphics& gfx )
{
	gfx.DrawRectDim ( x , y , width , height , c );

}

int Score::Increase ()
{
	if ( width == 800 )
	{
		return 0;
	}
	return width += 80;
}
