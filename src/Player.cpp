#include "../headers/Player.h"

Player::Player(float px, float py, float a, float rL, float sM, float sA, float f)
{
    pos[0] = px;
    pos[1] = py;
    angle = a;
    rayLength = rL;

    speedMove = sM;
    speedAngle = sA;
    fov = f;
}

Player::~Player()
{

}
