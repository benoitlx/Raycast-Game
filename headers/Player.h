#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    public:
        Player(float pos, float angle, float rayLength, float speedMove, float speedAngle, float fov);
        ~Player();

        float pos;
        float angle;  
        float rayLength;

        void move();

    protected:
        float speedMove;
        float speedAngle;
        float fov;
        


};

#endif