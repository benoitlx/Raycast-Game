#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "../headers/Player.h"
#include "../headers/Map.h"

#include <math.h>
#include <vector>

#define PI 3.14159


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

        void controller(sf::Time dt);
        void pollEvents();

        Map& map;

        /* Player */
        void initPlayer();
        Player* player;

        /* Window, Graphics */
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;

        std::vector<sf::RectangleShape> mapShape;
        sf::CircleShape pl;

        void initWindow();

        void render2d(unsigned int it);
        void render3d(unsigned int it); // Calcul ce qu'il faut afficher à chaque itération 

        /* Raycast Maths */
        inline float toRadian(float degree) { return (PI/180)*degree; }
        inline float dCos(float degree) { return cos(toRadian(degree)); }
        inline float dSin(float degree) { return sin(toRadian(degree)); }

        float interPos[2];
        int interType;
        float interLength;

        void raycast(unsigned int it, float posX, float posY); // met à jour la pos de l'inter de it, le type du mur, et la longeur

};

#endif