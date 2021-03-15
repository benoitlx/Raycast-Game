#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <math.h>

class Player
{
    public:
        Player(float px, float py, float a, float rL, float sM, float sA, float f);
        ~Player();

        float pos[2];
        float angle;  
        float rayLength;

        float speedMove;
        float speedAngle;
        float fov;
        


};

#endif