#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../headers/Player.h"
#include "../headers/Map.h"

class Game
{
    public:
        Game();
        ~Game();

        void update();
        void render();

        bool quit();
        bool pause();

    private:
        void render2d();
        void render3d();

        void controller();

        /* Raycast Maths */

};

#endif