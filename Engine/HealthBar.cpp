#include "HealthBar.h"

void HealthBar::Draw ( Graphics& gfx )
{
	gfx.DrawRectDim ( x , y , width , height , c );
}

int HealthBar::DamageTaken () 
{
	if ( width == 0 )
	{
		return 0;
	}
	return width -= 80;
}
