#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    public:
        Player(float px, float py, float a, float rL, float sM, float sA, float f);
        ~Player();

        float posx, posy;
        float angle;  
        float rayLength;

        void move();

    protected:
        float speedMove;
        float speedAngle;
        float fov;
        


};

#endif