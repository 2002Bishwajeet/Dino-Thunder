#include "main_menu.hpp"

#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context> &context) : m_context(context) , m_isPlayButtonSelected(true),
      m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
      m_isExitButtonPressed(false)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
    m_context->m_assets->loadFont(MAIN_FONT, "assets/fonts/8bitOperatorPlus8-Bold.ttf");
    m_context->m_assets->loadFont(SECONDARY_FONT, "assets/fonts/8bitOperatorPlusSC-Bold.ttf");
    

    // TITLE
    m_gametitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_gametitle.setString("Dino Thunder");
   m_gametitle.setOrigin(m_gametitle.getLocalBounds().width / 2,
                          m_gametitle.getLocalBounds().height / 2);
    m_gametitle.setPosition(m_context->m_window->getSize().x / 2-177.f,
                            m_context->m_window->getSize().y / 2 -200.f);
    m_gametitle.setCharacterSize(100);
    m_gametitle.setFillColor(sf::Color(245,171,53,255));


    // PLAY BUTTON
  
    m_playButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
      m_playButton.setCharacterSize(50);
    m_playButton.setString("Play");
   m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                          m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 );

    // Pause Button
    m_exitButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
      m_exitButton.setCharacterSize(50);
    m_exitButton.setString("Exit");
   m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                          m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 +100.f);

   
}
void MainMenu::ProcessInput()
{
    //  Event handling
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        //  Close window
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
            
         else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!m_isPlayButtonSelected)
                {
                    m_isPlayButtonSelected = true;
                    m_isExitButtonSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_isExitButtonSelected)
                {
                    m_isPlayButtonSelected = false;
                    m_isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                m_isPlayButtonPressed = false;
                m_isExitButtonPressed = false;

                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;
                }
                else
                {
                    m_isExitButtonPressed = true;
                }

                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void MainMenu::Update(sf::Time deltaTime) {
   if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Red);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Red);
        m_playButton.setFillColor(sf::Color::White);
    }
    
    if(m_isPlayButtonPressed)
    {
        // m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
    }
    else if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}
void MainMenu::Draw()
{
    //  Clear the window
    m_context->m_window->clear();

    // Draw Stuffs here
    m_context->m_window->draw(m_gametitle);
      m_context->m_window->draw(m_playButton);
        m_context->m_window->draw(m_exitButton);
    //  Display the window
    m_context->m_window->display();
}