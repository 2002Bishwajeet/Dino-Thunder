#include "game_play.hpp"
#include <SFML/Window/Event.hpp>
#include "pause_game.hpp"

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context),m_isJumping(false),m_jumpSpeed(25.0),m_playJumpSound(false)
{
}

GamePlay::~GamePlay()
{
}


 void GamePlay::Init() {

    //  Loading Assets for the game
     m_context->m_assets->loadTexture(BACKGROUND, "assets/sprites/background/layers/parallax-mountain.png");
     m_context->m_assets->loadTexture(FLOOR, "assets/sprites/floor/Wasteland-Files.png");
     m_context->m_assets->loadTexture(DINO, "assets/sprites/Dino/sheets/DinoSprites-tard.png");
     m_context->m_assets->loadSound(JUMP_SOUND, "assets/sounds/jump.wav");
     m_gameMusic.openFromFile("assets/music/game_music.ogg");


    //Jump Sound Setup
     m_jumpSound.setBuffer(m_context->m_assets->getSound(JUMP_SOUND));
    
    //  In Game Music Setup
     m_gameMusic.setLoop(true);
     m_gameMusic.setVolume(50);
     m_gameMusic.play();

    // Background Setup
    m_background.setTexture(m_context->m_assets->getTexture(BACKGROUND));
    m_background.setScale(5.f, 5.f);

    // Floor Setup
    m_floor.setTexture(m_context->m_assets->getTexture(FLOOR));
    m_floor.setTextureRect(sf::IntRect(100, 128, 16, 16));
    m_floor.setScale(5.f, 4.f);
    
    // TODO: Figure out a better way for the loop condition.
    //  What if you decided to increase the window size?
    for (int i = 0; i < 24; i++)
    {

    m_floor.setPosition(i*62.f, m_context->m_window->getSize().y-64 );
    m_floors.push_back(m_floor);
        
    }

    // Dino Setup
    m_dinoRect = sf::IntRect(0,0,24,24);
    m_dino.setTexture(m_context->m_assets->getTexture(DINO));
    m_dino.setTextureRect(m_dinoRect);
    // m_dino.setPosition(0, m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(24*4));
    m_dino.scale(4.f,4.f);

    
     
 }
 void GamePlay::Update(sf::Time deltaTime) {

 
    if(!m_isPaused)
    {
    

    //  Jumping Mechanics
    ////////
    //////////
    //////////
    /////////
    /////////
    if(y < m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4))                  //If you are above ground
      {  velocityY += gravity;     //Add gravity
          m_isJumping = true;
      }
    else if(y > m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4))             //If you are below ground
        y = m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4);                 //That's not supposed to happen, put him back up

    if(y == m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4))
    m_isJumping = false;
  
    m_dino.setPosition(x,y);
    y += velocityY;
    // End of Jumping Mechanics Code
    ////
    ///////
    ////////

    if(m_playJumpSound)
    {
        m_jumpSound.play();
        m_playJumpSound = false;
    }


    // UPDATE THE DINO ANIMATION
    ////
    /////
    /////
    //////

   if (clock.getElapsedTime().asSeconds() > 0.08f && !m_isJumping){
      if (m_dinoRect.left == 240)
        m_dinoRect.left = 120;
      else
        m_dinoRect.left += 24;

      m_dino.setTextureRect(m_dinoRect);
      clock.restart();
    }
    }
     
 }
 void GamePlay::ProcessInput() {
     //  Event handling
    sf::Event event;
    
    while (m_context->m_window->pollEvent(event))
    {
        //  Close window
        if (event.type == sf::Event::Closed)
         {  
            
              m_context->m_window->close();
              m_gameMusic.stop();
          
       
         }  
        else if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up) 
            { if(!m_isJumping)
                {
                    velocityY = -m_jumpSpeed;
                    m_isJumping = true;
                    m_playJumpSound = true;
                    m_dinoRect.left = 0;
                    m_dino.setTextureRect(m_dinoRect);
                }
               
            }
            if(event.key.code == sf::Keyboard::Escape)
            {
                m_context->m_state->AddState(std::make_unique<PauseGame>(m_context));
                m_isPaused = true;
            }
        }
     
    }
     
 }
 void GamePlay::Draw() {

     m_context->m_window->clear();
     m_context->m_window->draw(m_background);
     m_context->m_window->draw(m_dino);

     for (auto &floor : m_floors)
     {
         m_context->m_window->draw(floor);
     }
     
   
     m_context->m_window->display();
     
 }
 void GamePlay::Pause() {
     m_isPaused = true;
     m_gameMusic.pause();
 }
 void GamePlay::Start() {
        m_isPaused = false;
     m_gameMusic.play();
 }
