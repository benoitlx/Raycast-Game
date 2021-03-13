#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../headers/variables.h"

class Map
{
    protected:
        sf::RenderWindow& m_renderWindow;

        std::vector<std::vector<unsigned int>> m_vecMap;
        std::vector<sf::RectangleShape> m_vecBox;

    public:
        Map(sf::RenderWindow &renderWindow);
        void draw();
        int checkMapCase(unsigned int dx, unsigned int dy);
};

#endif