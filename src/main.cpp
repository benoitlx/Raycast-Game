#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/Game.h"

int main()
{
	Game game;

	while (true)
	{

		if (game.quit())
		{
			break;
		}else {

			if (game.pause())
			{
				; // display menu
			}else {
				
				game.update();

				game.render();
			}

		}

	}
}
