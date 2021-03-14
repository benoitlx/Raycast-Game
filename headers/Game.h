#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "../headers/Player.h"
#include "../headers/Map.h"

#include <math.h>
#include <vector>


/* Game Engine Class


*/

class Game
{
    public:
        Game(Map& m);
        ~Game();

        void update();
        void render();

        const bool running() const;
        const bool pause() const;

    protected:
        void initVariables();


        /* Controller */
        sf::Clock clock;

        void controller(sf::Time st);
        void pollEvents();

        Map& map;

        /* Window, Graphics */
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;

        void initWindow();

        void render2d();
        void render3d(unsigned int it); // Calcul ce qu'il faut afficher à chaque itération 

        /* Raycast Maths */
        float interPos[2];
        int interType;
        float interLength;

        void initRaycast();
        void raycast(unsigned int it, float posX, float posY); // met à jour la pos de l'inter de it, le type du mur, et la longeur

};

#endif