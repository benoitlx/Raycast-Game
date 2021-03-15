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
    this->videoMode.height = 600;
    this->videoMode.width = 800;


    this->window = new sf::RenderWindow(this->videoMode, "Raycasting", sf::Style::Titlebar | sf::Style::Close);

    
    for (unsigned int i = 0; i<map.vecMap.size(); i++)
    {
        for (unsigned int j = 0; j<map.vecMap[i].size(); j++)
        {
            if (map.vecMap[i][j] == 1)
            {
                sf::RectangleShape box(sf::Vector2f(map.blocSize/2, map.blocSize/2));
                box.setPosition(sf::Vector2f(i*map.blocSize/2+videoMode.width-150, j*map.blocSize/2+videoMode.height-150));
                mapShape.push_back(box);
            }
        }
    }

    pl.setRadius(2);
    pl.setFillColor(sf::Color(255, 0, 0));
    pl.setOrigin(sf::Vector2f(2, 2));

    pl.setPosition(sf::Vector2f(player->pos[0]/2+videoMode.width-150, player->pos[1]/2+videoMode.height-150));
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
        if(!map.vecMap[(player->pos[0] + addx)/map.blocSize][player->pos[1]/map.blocSize])
            player->pos[0] += addx;
        
        if(!map.vecMap[player->pos[0]/map.blocSize][(player->pos[1] + addy)/map.blocSize])
            player->pos[1] += addy;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(!map.vecMap[(player->pos[0] - addx)/map.blocSize][player->pos[1]/map.blocSize])
            player->pos[0] -= addx;
        
        if(!map.vecMap[player->pos[0]/map.blocSize][(player->pos[1] - addy)/map.blocSize])
            player->pos[1] -= addy;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->angle -= player->speedAngle*dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        player->angle += player->speedAngle*dt.asSeconds();

    if (player->angle > 360) player->angle = 0;
    if (player->angle < 0) player->angle = 360;

    pl.setPosition(sf::Vector2f(player->pos[0]/2+videoMode.width-150, player->pos[1]/2+videoMode.height-150));
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
    for (auto& vvec : mapShape)
        this->window->draw(vvec);

    this->window->draw(pl);
}

// 3d render of the game
void Game::render3d(unsigned int it)
{
    // this->raycast(it, 0, 0);
}

// render and display all the game
void Game::render()
{
    this->window->clear();

    // for ray in range(widthscreen)
    this->render3d(0);

    this->render2d(0);

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

    float nAngle = player->angle + player->fov/2 - it*(player->fov/videoMode.width);

    float a = dCos(nAngle);
    float b = dSin(nAngle);

    unsigned int iter = 0;
    interLength = 0;
    while (interLength < player->rayLength)
    {
        if (nAngle < 180 && nAngle > 0)
        {
            iter++;
        }else{
            iter--;
        }

        // solve x
        int nextCaseX = (std::floor(posX/map.blocSize)+iter)*map.blocSize;

        float y = b/a*(nextCaseX-posX)+posY;

        float deltaxX = nextCaseX - posX;
        float delatyX = y - posY;
        float distX = std::sqrt(delatyX*delatyX + deltaxX*deltaxX);

        // solve y
        int nextCaseY = (std::floor(posY/map.blocSize)+iter)*map.blocSize;

        float x = a/b*(nextCaseY-posY)+posX;

        float deltaxY = x - posX;
        float delatyY = nextCaseY - posY;
        float distY = std::sqrt(delatyY*delatyY + deltaxY*deltaxY);

        if (!(map.vecMap[(int)x / map.blocSize][nextCaseY/map.blocSize] || map.vecMap[(int)x / map.blocSize][nextCaseY/map.blocSize-1]))
        {
            interLength = distX;
        }
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



