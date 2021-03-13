#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../headers/variables.h"
#include "../headers/Map.h"

#include <math.h>


class Camera
{
    protected:
        Map& m_map;
        sf::RenderWindow& m_renderWindow;
        sf::CircleShape m_camera;
        sf::Vector2f m_position, m_intersection;
        sf::Clock m_clock;

        float m_angle, m_fov, m_rayLenght;
        float m_radius;
        float m_speedMove, m_speedAngle;

        std::vector<sf::VertexArray> m_vecRays;
        std::vector<float> m_lengthRays;
        std::vector<int> tiles_types;

    public:
        Camera(sf::RenderWindow& RenderWindow, Map& map);
        void draw();
        void update();
        void project();
        void checkKeyboardHit(sf::Time st);
        int intersect(unsigned int it, float pos_x, float pos_y);

        inline float toRadian(float degree) { return (PI/180)*degree; }
        inline float dCos(float degree) { return cos(toRadian(degree)); }
        inline float dSin(float degree) { return sin(toRadian(degree)); }

};

#endif