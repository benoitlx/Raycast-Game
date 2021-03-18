#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/Game.h"

int main()
{
	Map _map("/home/benoitl/Dev/cpp/raycastingv2.0/ressources/map/map.txt", 80);
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
