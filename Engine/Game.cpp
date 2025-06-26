/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng ( std::random_device ()() )
	
	
	
	
{
	
	for ( int i = 0; i < nDrops; i++ )
	{
		drop [i].Init ( rng );
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if ( !isGameOver )
	{


		paddle.ClampToScreen ();
		playerMoveCounter++;
		if ( playerMoveCounter >= playerMovePeriod )
		{
			paddle.PaddleMove ( wnd.kbd );

			playerMoveCounter = 0;
			rainMoveCounter++;

		}

		
		if ( rainMoveCounter >= rainMovePeriod )
		{
			for ( int i = 0; i < nDrops; i++ )
			{
				drop [i].Speed ();
				if ( drop [i].GetY () == gfx.ScreenHeight )
				{
					drop [i].Respawn ( rng );
					if ( nDrops != nMaxDrop )
					{
						nDrops++;

					}
				}
				rainMoveCounter = 0;

			}
		}
	}


	for ( int i = 0; i < nDrops; i++ )
	{
		if ( paddle.IsHit ( drop [i] ) )
		{
			isInvulnerable = true;
		}
	}
	if ( isInvulnerable )
	{
		iFrames++;
		isInvulnerable = false;
	}
	if ( iFrames >= invulnerableFrames )
	{
		iFrames = 0;
		paddle.TakeHealth ();
		hp.DamageTaken ();


	}
		if ( paddle.GetHealth () == 0 )
		{
			isGameOver = true;

		}
	
	
}

void Game::ComposeFrame()
{
	hp.Draw ( gfx );
	for ( int i = 0; i < nDrops; i++ )
	{
		drop [i].Draw ( gfx );

	}
	paddle.Draw ( gfx );
	
}
