#include "../headers/Game.h"


// ========================================================================================
// Initialization
// ========================================================================================

void Game::initVariables()
{
    this->window = nullptr;

}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;


    this->window = new sf::RenderWindow(this->videoMode, "Raycasting", sf::Style::Titlebar | sf::Style::Close);

}

void initRaycast()
{

}

Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
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

}

// 3d render of the game
void Game::render3d(unsigned int it)
{

}

// render and display all the game
void Game::render()
{
    this->window->clear(sf::Color(255, 0, 0, 255));

    this->render2d();
    this->render3d(0);

    this->window->display();
}


// retourne les coord de l'intersection du rayon et du mur, la distance et le type du mur (type à changer) 
int raycast(unsigned int it)
{

}

























const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::pause() const
{
    return false;
}



