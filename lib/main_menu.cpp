#include "main_menu.hpp"
#include "game_play.hpp"
#include <SFML/Window/Event.hpp>
#include<SFML/Audio.hpp>

// Initialize the main menu Constructor with all the default values
MainMenu::MainMenu(std::shared_ptr<Context> &context) : m_context(context) , m_isPlayButtonSelected(true),
      m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
      m_isExitButtonPressed(false)
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
    m_context->m_assets->loadFont(MAIN_FONT, "assets/fonts/8bitOperatorPlus8-Bold.ttf");
    m_context->m_assets->loadFont(SECONDARY_FONT, "assets/fonts/8bitOperatorPlusSC-Bold.ttf");
    m_context->m_assets->loadSound(MAIN_MENU_MUSIC, "assets/music/mainmenu.ogg");
    
    // Code for creating a cloud - by @oceanofamisha
    m_cloud.setFillColor(sf::Color(221,231,238));
    m_cloud.setOutlineColor(sf::Color(129,165,186));

    m_cloud.setPointCount(29);

    m_cloud.setOrigin(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y/2);

    m_cloud.setPoint(0, sf::Vector2f(300.f, 500.f));
    m_cloud.setPoint(1, sf::Vector2f(305.f, 490.f));
    m_cloud.setPoint(2, sf::Vector2f(310.f, 480.f));
    m_cloud.setPoint(3, sf::Vector2f(315.f, 470.f));
    m_cloud.setPoint(4, sf::Vector2f(320.f, 460.f));
    m_cloud.setPoint(5, sf::Vector2f(325.f, 455.f));
    m_cloud.setPoint(6, sf::Vector2f(330.f, 450.f));
    m_cloud.setPoint(7, sf::Vector2f(335.f, 445.f));
    m_cloud.setPoint(8, sf::Vector2f(340.f, 440.f));
    m_cloud.setPoint(9, sf::Vector2f(390.f, 435.f));
    m_cloud.setPoint(10, sf::Vector2f(400.f, 430.f));
    m_cloud.setPoint(11, sf::Vector2f(420.f, 420.f));
    m_cloud.setPoint(12, sf::Vector2f(450.f, 415.f));
    m_cloud.setPoint(13, sf::Vector2f(475.f, 410.f));
    m_cloud.setPoint(14, sf::Vector2f(500.f, 390.f));
    m_cloud.setPoint(15, sf::Vector2f(525.f, 385.f));
    m_cloud.setPoint(16, sf::Vector2f(550.f, 370.f));
    m_cloud.setPoint(17, sf::Vector2f(600.f, 350.f)); 
    m_cloud.setPoint(18, sf::Vector2f(640.f, 355.f));
    m_cloud.setPoint(19, sf::Vector2f(675.f, 360.f));
    m_cloud.setPoint(20, sf::Vector2f(685.f, 370.f));
    m_cloud.setPoint(21, sf::Vector2f(700.f, 375.f));
    m_cloud.setPoint(22, sf::Vector2f(710.f, 400.f));
    m_cloud.setPoint(23, sf::Vector2f(755.f, 440.f));
    m_cloud.setPoint(24, sf::Vector2f(760.f, 465.f));
    m_cloud.setPoint(25, sf::Vector2f(780.f, 470.f));
    m_cloud.setPoint(26, sf::Vector2f(795.f, 485.f));
    m_cloud.setPoint(27, sf::Vector2f(800.f, 490.f));
    m_cloud.setPoint(28, sf::Vector2f(800.f, 500.f));
    
    m_cloud.setScale(0.5f, 0.5f);   
     m_cloud.setPosition( 350, 30);

//  TODO: Figure out a way to use the music object from assets
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
   m_gametitle.setOrigin(m_gametitle.getLocalBounds().width / 2,
                          m_gametitle.getLocalBounds().height / 2);
    //  Set the position
    m_gametitle.setPosition(m_context->m_window->getSize().x / 2-177.f,
                            m_context->m_window->getSize().y / 2 -200.f);
    //  Set Size
    m_gametitle.setCharacterSize(100);
    //  Set the color
    m_gametitle.setFillColor(sf::Color(245,171,53,255));


    // PLAY BUTTON
    //  Set font need a reference to the font object
    m_playButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
    //  Set the Character Size to the title
      m_playButton.setCharacterSize(50);
    //  Set the text to the title
    m_playButton.setString("Play");
    //  Set the Origin 
   m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                          m_playButton.getLocalBounds().height / 2);
    //  Set the position
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 );

    // Pause Button
    //  Set font need a reference to the font object
    m_exitButton.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
    //  Set the Character Size to the title
      m_exitButton.setCharacterSize(50);
    //  Set the text to the title
    m_exitButton.setString("Exit");
    //  Set the Origin
   m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                          m_exitButton.getLocalBounds().height / 2);
    //  Set the position
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

void MainMenu::Update(sf::Time deltaTime) {

    // Update the text objects with respect to the keyboard input
   if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Red);
        m_exitButton.setFillColor(sf::Color(192,192,192));
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Red);
        //  Grey Shade
        m_playButton.setFillColor(sf::Color(192,192,192));
    }
    
    if(m_isPlayButtonPressed)
    {
        m_context->m_state->AddState(std::make_unique<GamePlay>(m_context), true);
    }
    else if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
        m_music.stop();
        m_music.~Music();

    }

    // TODO: Reset the position of the cloud when it reaches the end of the screen
   m_cloud.move(0.2f,0.f);
}
void MainMenu::Draw()
{
   
    //  Clear the window
    m_context->m_window->clear(
        //  White Shade
        sf::Color(254,255,254)
    );
  

    // Draw Stuffs here

    // Drawing Clouds
    m_context->m_window->draw(m_cloud);


    //  Drawing Main Menu Text
    m_context->m_window->draw(m_gametitle);
    // Drawing Play Button
      m_context->m_window->draw(m_playButton);
    //   Drawing Exit Button
        m_context->m_window->draw(m_exitButton);
    //  Display the window
    m_context->m_window->display();
}