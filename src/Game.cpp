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
                sf::RectangleShape box(sf::Vector2f(4, 4));
                box.setPosition(sf::Vector2f(i*4, j*4));
                mapShape.push_back(box);
            }
        }
    }
}

void Game::initRaycast()
{
    
}

void Game::initPlayer()
{
    this->player = new Player(3*map.blocSize, 3*map.blocSize, 90, 300, 100, 75, 60);
}

Game::Game(Map& m) : 
    map(m)
{
    this->initVariables();
    this->initWindow();
    this->initRaycast();
    this->initPlayer();
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

// update Player position, enemies position, actualize variable...
void Game::update()
{
    this->pollEvents();
}


//render map
void Game::render2d()
{
    for (auto& vvec : mapShape)
        this->window->draw(vvec);
}

// 3d render of the game
void Game::render3d(unsigned int it)
{
    this->raycast(it, 0, 0);
}

// render and display all the game
void Game::render()
{
    this->window->clear();

    this->render2d();

    // for ray in range(widthscreen)
    this->render3d(0);

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
}

























const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::pause() const
{
    return false;
}



