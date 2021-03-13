#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/variables.h"
#include "../headers/Camera.h"
#include "../headers/Map.h"

int main()
{
	sf::RenderWindow _window(sf::VideoMode(WIDTHSCREEN*1.5, HEIGHTSCREEN), "First Raycast Test", sf::Style::Titlebar);
	_window.setFramerateLimit(60);

	Map _map(_window);
	Camera _camera(_window, _map);

	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					_window.close();
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape)
						_window.close();
					break;
			}
		}
		_camera.update();
		_window.clear();

		_camera.draw();
		//_map.draw();

		_window.display();
	}
}
