#include "game_play.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context),m_isJumping(false),m_jumpSpeed(25.0)
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
     m_gameMusic.openFromFile("assets/music/game_music.ogg");

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

    
    if(y < m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4))                  //If you are above ground
        velocityY += gravity;    //Add gravity
    else if(y > m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4))             //If you are below ground
        y = m_context->m_window->getSize().y - m_floor.getGlobalBounds().height-(22*4);                 //That's not supposed to happen, put him back up

    
  
    m_dino.setPosition(x,y);
    y += velocityY;
     
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
            {
               velocityY = -m_jumpSpeed;
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
