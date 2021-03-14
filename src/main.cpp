#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/Game.h"

int main()
{
	Map _map("../ressources/map/map.txt");
	Game game(_map);
	
	while (game.running())
	{
		if (game.pause())
		{
			; // display menu
		}else {

			game.update();

			game.render();
		}
	}
}
