#include "../headers/Camera.h"
#include "../headers/Map.h"

Camera::Camera(sf::RenderWindow& renderWindow, Map& map) :
    m_renderWindow(renderWindow), m_map(map)
{
    m_radius = 6;
    m_camera.setRadius(m_radius);
    m_camera.setFillColor(sf::Color(255, 0, 0));
    m_camera.setOrigin(sf::Vector2f(m_radius, m_radius));

    m_speedMove = 100.0f;
    m_speedAngle = 125.0f;
    
    m_position = {120, 200};

    m_fov = 70;
    m_rayLenght = 1000;


    for (unsigned int i = 0; i < WIDTHSCREEN; i++)
    {
        sf::VertexArray ray(sf::Lines, 2);
        ray[0].color = sf::Color::Green;
        ray[1].color = sf::Color::Green;

        m_vecRays.push_back(ray);
    }
}



void Camera::draw()
{
    /* 2D Render */
    //for (auto& vvec : m_vecRays)
    //    m_renderWindow.draw(vvec);
    //m_renderWindow.draw(m_camera);

    /* 3D Render */
    
    for (int i=0; i< m_lengthRays.size(); i++)
    {   
        switch (tiles_types[i]){
            case 1:
            {
                int color;
                if (int(m_vecRays[i][1].position.x) % blocSize == 0) { color = 255; } else { color = 100; }

                sf::Vertex line[] = 
                {
                    sf::Vertex(sf::Vector2f(i, HEIGHTSCREEN/2-900/(sqrt(m_lengthRays[i]))), sf::Color(color, 0, 0)),
                    sf::Vertex(sf::Vector2f(i, HEIGHTSCREEN/2+900/(sqrt(m_lengthRays[i]))), sf::Color(color, 0, 0))
                };

                m_renderWindow.draw(line, 5, sf::Lines);
            }
                break;
            case 2:
                break;
        }
        

        /* Sol */
        sf::Vertex sol[] = 
        {
            sf::Vertex(sf::Vector2f(i, HEIGHTSCREEN/2+900/(sqrt(m_lengthRays[i]))), sf::Color(128, 128, 128)), 
            sf::Vertex(sf::Vector2f(i, HEIGHTSCREEN), sf::Color(128, 128, 128))
        };
        
        m_renderWindow.draw(sol, 5, sf::Lines);
    }
}



void Camera::update()
{
    sf::Time dt = m_clock.restart();
    checkKeyboardHit(dt);
    project();
}



void Camera::project()
{
    m_lengthRays.clear();
    tiles_types.clear();

    for (unsigned int i = 0; i < m_vecRays.size(); i++)
    {
        m_vecRays[i][0].position = m_position;

        tiles_types.push_back(intersect(i, m_position.x, m_position.y));
        
        m_vecRays[i][1].position = m_intersection;
      
        float len = sqrt(pow((m_vecRays[i][0].position.x - m_vecRays[i][1].position.x), 2) + 
                         pow((m_vecRays[i][0].position.y - m_vecRays[i][1].position.y), 2));

        m_lengthRays.push_back(len);
    }    
}


void Camera::checkKeyboardHit(sf::Time dt)
{
    float addx = dCos(m_angle)*m_speedMove*dt.asSeconds();
    float addy = dSin(m_angle)*m_speedMove*dt.asSeconds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if(!m_map.checkMapCase((m_position.x + addx)/blocSize, m_position.y/blocSize))
            m_position.x += addx;
        
        if(!m_map.checkMapCase(m_position.x/blocSize, (m_position.y + addy)/blocSize))
            m_position.y += addy;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(!m_map.checkMapCase((m_position.x - addx)/blocSize, m_position.y/blocSize))
            m_position.x -= addx;

        if(!m_map.checkMapCase(m_position.x/blocSize, (m_position.y - addy)/blocSize)) 
            m_position.y -= addy; 
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_angle -= m_speedAngle*dt.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        m_angle += m_speedAngle*dt.asSeconds();
    

    

    if (m_angle > 360) m_angle = 0;
    if (m_angle < 0) m_angle = 360;

    m_camera.setPosition(m_position);
    m_camera.setRotation(m_angle);
}



int Camera::intersect(unsigned int it, float pos_x, float pos_y)
{
    float fAngle = (m_angle + m_fov/2 - it*(m_fov/WIDTHSCREEN));
    sf::Vector2f direction = {dCos(fAngle), dSin(fAngle)};

    for (unsigned int l=0; l<m_rayLenght; l++)
    {
        int dx = (int)(pos_x + l * direction.x);
        int dy = (int)(pos_y + l * direction.y);

        int offset = 0;
        if (m_angle>90 && m_angle<270)
        {
            offset = 1;
        }

        if (m_map.checkMapCase((dx-offset)/blocSize, (dy-offset)/blocSize))
        {
            m_intersection.x = dx;
            m_intersection.y = dy;
            return m_map.checkMapCase((dx-offset)/blocSize, (dy-offset)/blocSize);
        }
    }
    return 0;
}


