#include "game.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game() : m_context(std::make_shared<Context>())

{
    // Creating a render window
    //  We are gonna keep the main window in 720p i.e 1280x720 px and in Windowed mode
    // Here window is an object of class RenderWindow and constructor called
    m_context->m_window->create(sf::VideoMode(1280, 720), "Dinosour Game", sf::Style::Close);

    // We will set the framerate to 60 for the current application
    m_context->m_window->setFramerateLimit(60);
    m_context->m_window->setVerticalSyncEnabled(true);
    // TODO: ADD a new State
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::Run()
{

    sf::CircleShape circle(100.f);

    //  Now we will use this object to imply certain conditions
    while (m_context->m_window->isOpen())
    {
        //  Event handling
        sf::Event event;
        while (m_context->m_window->pollEvent(event))
        {
            //  Close window
            if (event.type == sf::Event::Closed)
                m_context->m_window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                m_context->m_window->close();
        }

        //  Clear the window
        m_context->m_window->clear();

        // Draw Stuffs here

        //  Display the window
        m_context->m_window->display();
    }
}