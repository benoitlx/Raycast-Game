#include "../headers/Game.h"


// ========================================================================================
// Initialization
// ========================================================================================

void Game::initVariables()
{
    this->window = nullptr;
    this->player = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 800;
    this->videoMode.width = 800;


    this->window = new sf::RenderWindow(this->videoMode, "Raycasting Game", sf::Style::Titlebar | sf::Style::Close);

    
    for (unsigned int i = 0; i<map.vecMap.size(); i++)
    {
        for (unsigned int j = 0; j<map.vecMap[i].size(); j++)
        {
            if (map.vecMap[j][i])
            {
                sf::RectangleShape box(sf::Vector2f(map.blocSize, map.blocSize));
                box.setPosition(sf::Vector2f(i*map.blocSize, j*map.blocSize));
                mapShape.push_back(box);
            }
        }
    }

    pl.setRadius(2);
    pl.setFillColor(sf::Color(255, 0, 0));
    pl.setOrigin(sf::Vector2f(2, 2));

    pl.setPosition(sf::Vector2f(player->pos[0], player->pos[1]));

    for (unsigned int i=0; i<videoMode.width; i++)
    {
        sf::VertexArray ray(sf::Lines, 2);
        ray[0].color = sf::Color(0, 255, 0);
        ray[1].color = sf::Color(0, 255, 0);

        vecRays.push_back(ray);
    }
}


void Game::initPlayer()
{
    this->player = new Player(3*map.blocSize, 3*map.blocSize, 90, 300, 100, 75, 60);
}

Game::Game(Map& m) : 
    map(m)
{
    this->initVariables();
    this->initPlayer();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
}







// =================================================================================================
// Functions 
// =================================================================================================

// to close and manage window
void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::controller(sf::Time dt)
{
    float addx = dCos(player->angle)*player->speedMove*dt.asSeconds();
    float addy = dSin(player->angle)*player->speedMove*dt.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if(!map.vecMap[player->pos[1]/map.blocSize][(player->pos[0] + addx)/map.blocSize])
            player->pos[0] += addx;
        
        if(!map.vecMap[(player->pos[1] + addy)/map.blocSize][player->pos[0]/map.blocSize])
            player->pos[1] += addy;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(!map.vecMap[player->pos[1]/map.blocSize][(player->pos[0] - addx)/map.blocSize])
            player->pos[0] -= addx;
        
        if(!map.vecMap[(player->pos[1] - addy)/map.blocSize][player->pos[0]/map.blocSize])
            player->pos[1] -= addy;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        player->angle -= player->speedAngle*dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->angle += player->speedAngle*dt.asSeconds();

    if (player->angle > 360) player->angle = 0;
    if (player->angle < 0) player->angle = 360;

    pl.setPosition(sf::Vector2f(player->pos[0], player->pos[1]));
    pl.setRotation(player->angle);
}

// update Player position, enemies position, actualize variable, chek inputs, manage time...
void Game::update()
{
    sf::Time dt = clock.restart();

    this->pollEvents();
    this->controller(dt);
}


//render map
void Game::render2d(unsigned int it)
{
    for (auto& wall : mapShape)
        this->window->draw(wall);

    for (auto& ray : vecRays)
        this->window->draw(ray);

    this->window->draw(pl);
}

// 3d render of the game
void Game::render3d(unsigned int it)
{
    
}

// render and display all the game
void Game::render()
{
    this->window->clear();

    // for ray in range(widthscreen)
    for (unsigned int it = 0; it<videoMode.width; it++)
    {
        this->raycast(it, player->pos[0], player->pos[1]);
        std::cout << "new call" << std::endl;

        // vecRays[it][0] = sf::Vector2f(player->pos[0], player->pos[1]);
        // vecRays[it][1] = sf::Vector2f(interPos[0], interPos[1]);
        vecRays[it][0] = sf::Vertex(sf::Vector2f(player->pos[0], player->pos[1]), sf::Color(0, 255, 0));
        vecRays[it][1] = sf::Vertex(sf::Vector2f(interPos[0], interPos[1]), sf::Color(0, 255, 0));
        

        this->render3d(it);
        this->render2d(it);
    } 

    this->window->display();
}












// retourne les coord de l'intersection du rayon et du mur, la distance et le type du mur (type à changer) 
void Game::raycast(unsigned int it, float posX, float posY)
{
    /* Raycast

        - met à jour la position de l'intersection
        - met à jour le type du mur intersecté
        - met à jour la longueur du rayon
    */
    std::cout << it << "/" << videoMode.width << "\n";
    std::cout << posX << " " << posY << "\n";
    
    float nAngle = player->angle + player->fov/2 - it*2*(player->fov/videoMode.width);

    double a = dCos(nAngle);
    double b = dSin(nAngle);

    
    

    int mapX = int(posX/map.blocSize);
    int mapY = int(posY/map.blocSize);

    double rlx;
    double rly;

    double deltaX = std::abs(map.blocSize / a);
    double deltaY = std::abs(map.blocSize / b);
    std::cout << a << " " << b << "\n";

    int stepX;
    int stepY;

    int side;

    bool hit = false;

    if (a < 0)
    {
        stepX = -1;
        rlx = (posX/map.blocSize - mapX) * deltaX;
    }
    else
    {
        stepX = 1;
        rlx = (mapX + 1.0 - posX/map.blocSize) * deltaX;
    }
    if (b < 0)
    {
        stepY = -1;
        rly = (posY/map.blocSize - mapY) * deltaY;
    }
    else
    {
        stepY = 1;
        rly = (mapY + 1.0 - posY/map.blocSize) * deltaY;
    }

    while (hit == 0)
    {
        if (rlx < rly){
            rlx += deltaX;
            mapX += stepX;
            side = 0;
        }else{
            rly += deltaY;
            mapY += stepY;
            side = 1;
        }
        if (map.vecMap[mapY][mapX]) hit = 1;     
    }
    
    std::cout << rlx << " " << rly << "\n";

    if (side == 0)
    {
        interPos[0] = posX + rlx*a;
        interPos[1] = posY + rlx*b;
    }else{
        interPos[0] = posX + rly*a;
        interPos[1] = posY + rly*b;
    } 
}

























const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::pause() const
{
    return false;
}



