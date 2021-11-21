#include "main_menu.hpp"
#include "game_play.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>

// Initialize the main menu Constructor with all the default values
MainMenu::MainMenu(std::shared_ptr<Context>& context)
    : m_context(context)
    , m_isPlayButtonSelected(true)
    , m_isPlayButtonPressed(false)
    , m_isExitButtonSelected(false)
    , m_isExitButtonPressed(false)
{
}

MainMenu::~MainMenu()
{
}

// Function init method to load or set the stage of the main menu
void MainMenu::Init()
{
    //  Loading the fonts from the file and storing it in the map
    //  MAIN_FONT and SECONDARY_FONT are the enums for the fonts which will used to identify
    m_context->m_assets->loadTexture(BACKGROUND, "assets/sprites/background/layers/parallax-mountain.png");
    m_context->m_assets->loadFont(MAIN_FONT, "assets/fonts/8bitOperatorPlus8-Bold.ttf");
    m_context->m_assets->loadFont(SECONDARY_FONT, "assets/fonts/8bitOperatorPlusSC-Bold.ttf");
    m_context->m_assets->loadTexture(CLOUD, "assets/sprites/clouds/Clouds.png");

    // Background Setup
    m_background.setTexture(m_context->m_assets->getTexture(BACKGROUND));
    m_background.setScale(5.f, 5.f);

    for (auto& cloud : m_clouds)
    {
        cloud.setTexture(m_context->m_assets->getTexture(CLOUD));
        cloud.setScale(2.5f, 2.5f);
    }
    m_clouds[0].setTextureRect(sf::IntRect(8, 13, 60, 35));
    m_clouds[0].setPosition(0, m_clouds[0].getLocalBounds().height / 2);
    m_clouds[0].setRotation(-10);

    m_clouds[1].setTextureRect(sf::IntRect(81, 24, 30, 20));
    m_clouds[1].setPosition(m_context->m_window->getSize().x - 80, m_clouds[1].getLocalBounds().height / 2 + 50);

    m_clouds[2].setTextureRect(sf::IntRect(8, 55, 34, 23));
    m_clouds[2].setPosition(250, m_clouds[2].getLocalBounds().height / 2 + 120);

    m_clouds[3].setTextureRect(sf::IntRect(67, 55, 50, 29));
    m_clouds[3].setPosition(500, m_clouds[3].getLocalBounds().height / 2 + 50);

    m_clouds[4].setTextureRect(sf::IntRect(16, 86, 41, 28));
    m_clouds[4].setPosition(800, m_clouds[4].getLocalBounds().height / 2 + 150);
    m_clouds[4].setRotation(-14);

    m_music.openFromFile("assets/music/mainmenu.ogg");
    m_music.setLoop(true);
    m_music.setVolume(75);

    // Never call the play method inside the loop
    //  It will restart again and again
    m_music.play();

    //  Applying the fonts to the text objects

    // TITLE
    //  Set font need a reference to the font object
    m_gametitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    //  Set the text to the title
    m_gametitle.setString("Dino Thunder");
    //  Set the Origin
    m_gametitle.setOrigin(m_gametitle.getLocalBounds().width / 2, m_gametitle.getLocalBounds().height / 2);
    //  Set the position
    m_gametitle.setPosition(m_context->m_window->getSize().x / 2 - 177.f, m_context->m_window->getSize().y / 2 - 200.f);
    //  Set Size
    m_gametitle.setCharacterSize(100);
    //  Set the color
    m_gametitle.setFillColor(sf::Color(245, 171, 53, 255));

    // PLAY BUTTON
    //  Set font need a reference to the font object
    m_playButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
    //  Set the Character Size to the title
    m_playButton.setCharacterSize(50);
    //  Set the text to the title
    m_playButton.setString("Play");
    //  Set the Origin
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2, m_playButton.getLocalBounds().height / 2);
    //  Set the position
    m_playButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2);

    // Pause Button
    //  Set font need a reference to the font object
    m_exitButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
    //  Set the Character Size to the title
    m_exitButton.setCharacterSize(50);
    //  Set the text to the title
    m_exitButton.setString("Exit");
    //  Set the Origin
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2, m_exitButton.getLocalBounds().height / 2);
    //  Set the position
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 100.f);
}
void MainMenu::ProcessInput()
{
    //  Event handling
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        //  Close window
        if (event.type == sf::Event::Closed)
        {
            m_music.stop();
            m_music.~Music();
            m_context->m_window->close();
        }
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
                    m_music.stop();
                    m_music.~Music();
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

void MainMenu::Update(sf::Time deltaTime)
{
    // Update the text objects with respect to the keyboard input
    if (m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Red);
        m_exitButton.setFillColor(sf::Color(192, 192, 192));
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Red);
        //  Grey Shade
        m_playButton.setFillColor(sf::Color(192, 192, 192));
    }

    if (m_isPlayButtonPressed)
    {
        m_context->m_state->AddState(std::make_unique<GamePlay>(m_context), true);
    }
    else if (m_isExitButtonPressed)
    {
        m_context->m_window->close();
        m_music.stop();
        m_music.~Music();
    }

    for (auto& cloud : m_clouds)
    {
        cloud.move(4.f / cloud.getLocalBounds().width, 0.f);
        if (cloud.getPosition().x > m_context->m_window->getSize().x + 60)
        {
            cloud.setPosition(0.f - 40.f, cloud.getPosition().y);
        }
    }
}
void MainMenu::Draw()
{
    //  Clear the window
    m_context->m_window->clear(
        //  White Shade
        sf::Color(254, 255, 254));

    // Draw Stuffs here

    // Drawing Background
    m_context->m_window->draw(m_background);

    // Drawing Clouds
    for (auto& cloud : m_clouds)
    {
        m_context->m_window->draw(cloud);
    }

    // m_context->m_window->draw(tempcloud);

    //  Drawing Main Menu Text
    m_context->m_window->draw(m_gametitle);
    // Drawing Play Button
    m_context->m_window->draw(m_playButton);
    //   Drawing Exit Button
    m_context->m_window->draw(m_exitButton);
    //  Display the window
    m_context->m_window->display();
}