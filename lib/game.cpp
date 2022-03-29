#include "game.hpp"
#include "main_menu.hpp"
#include <SFML/Window/Event.hpp>

Game::Game()
    : m_context(std::make_shared<Context>()) // Make sure to initalise the
                                             // m_context pointer

{
    // Creating a render window
    //  We are gonna keep the main window in 720p i.e 1280x720 px and in
    //  Windowed mode
    // Here we are using m_context to get the window pointer to create the
    // window
    m_context->m_window->create(sf::VideoMode(1280, 720), "Dinosour Game",
                                sf::Style::Close);

    //  We will be adding a new State to the stack
    //  The state will be the Main Menu
    m_context->m_state->AddState(std::make_unique<MainMenu>(m_context));

    // We will set the framerate to 60 for the current application
    m_context->m_window->setFramerateLimit(60);

    //  We will set the VSync to true for the current application to avoid the
    //  screen tearing
    m_context->m_window->setVerticalSyncEnabled(true);

    m_context->m_window->setKeyRepeatEnabled(false);
}

Game::~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //  Now we will use this object to imply certain conditions

    while (m_context->m_window->isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        //  We will now update the screen every 1/60th of a second
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;

            // State change before updating the screen
            m_context->m_state->ProcessStateChange();
            //  State to mange the keyinputs
            m_context->m_state->GetCurrentState()->ProcessInput();
            //  State to update the screen
            m_context->m_state->GetCurrentState()->Update(TIME_PER_FRAME);
            //  State to draw the screen
            m_context->m_state->GetCurrentState()->Draw();
        }
    }
}