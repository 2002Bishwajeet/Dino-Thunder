#include "game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "main_menu.hpp"

Game::Game() : m_context(std::make_shared<Context>())

{
    // Creating a render window
    //  We are gonna keep the main window in 720p i.e 1280x720 px and in Windowed mode
    // Here window is an object of class RenderWindow and constructor called
    m_context->m_window->create(sf::VideoMode(1280, 720), "Dinosour Game", sf::Style::Close);
    m_context->m_state->AddState(std::make_unique<MainMenu>(m_context));
    // We will set the framerate to 60 for the current application
    m_context->m_window->setFramerateLimit(60);
    m_context->m_window->setVerticalSyncEnabled(true);
   
    
}

Game::~Game()
{
    //dtor
}

void Game::Run()
{

    sf::CircleShape circle(100.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //  Now we will use this object to imply certain conditions
    while (m_context->m_window->isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > TIME_PER_SECOND)
        {
            timeSinceLastUpdate -= TIME_PER_SECOND;

           
            m_context->m_state->ProcessStateChange();
            m_context->m_state->GetCurrentState()->ProcessInput();
            m_context->m_state->GetCurrentState()->Update(TIME_PER_SECOND);
            m_context->m_state->GetCurrentState()->Draw();
          
        }
    }
}