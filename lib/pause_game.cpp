#include "pause_game.hpp"
#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context>& context)
{
    m_context = context;
}

PauseGame::~PauseGame()
{
}

void PauseGame::Init()
{
    m_pauseTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_pauseTitle.setString("Pause");
    m_pauseTitle.setCharacterSize(100);
    m_pauseTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2);
}
void PauseGame::ProcessInput()
{
    //  Event handling
    sf::Event event;

    while (m_context->m_window->pollEvent(event))
    {
        //  Close window
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                m_context->m_state->Popcurrent();
            }
        }
    }
}
void PauseGame::Update(sf::Time deltaTime)
{
    //  We don't need to update anything here so we will keep this empty
}
void PauseGame::Draw()
{
    m_context->m_window->draw(m_pauseTitle);
    m_context->m_window->display();
}