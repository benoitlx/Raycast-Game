#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    public:
        float pos;  

        void move();

    protected:
        float speedMove, speedAngle;


};

#endif