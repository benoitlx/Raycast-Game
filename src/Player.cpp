#include "../headers/Player.h"

Player::Player(float px, float py, float a, float rL, float sM, float sA, float f)
{
    posx = px;
    posy = py;
    angle = a;
    rayLength = rL;

    speedMove = sM;
    speedAngle = sA;
    fov = f;
}

Player::~Player()
{

}