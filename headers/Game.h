#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "../headers/Player.h"
#include "../headers/Map.h"

#include <math.h>

/* Game Engine Class


*/

class Game
{
    public:
        Game();
        ~Game();

        void update();
        void render();

        const bool running() const;
        const bool pause() const;

    protected:
        void initVariables();

        void controller();
        void pollEvents();

        /* Window, Graphics */
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;

        void initWindow();

        void render2d();
        void render3d(unsigned int it); // Calcul ce qu'il faut afficher à chaque itération 

        /* Raycast Maths */
        void initRaycast();
        int raycast(unsigned int it); // retourne la pos de l'inter de it, le type du mur, et la longeur

};

#endif