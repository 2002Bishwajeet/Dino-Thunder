#include "game_play.hpp"
#include "game_over.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context),m_isJumping(false),m_jumpSpeed(23.0),m_playJumpSound(false)
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
     m_context->m_assets->loadTexture(OBSTACLE_1,"assets/sprites/obstacles/winter_tree_1.png");
     m_context->m_assets->loadTexture(OBSTACLE_2,"assets/sprites/obstacles/winter_tree_2.png");
     m_context->m_assets->loadTexture(OBSTACLE_3,"assets/sprites/obstacles/winter_tree_3.png");
     m_context->m_assets->loadTexture(OBSTACLE_4,"assets/sprites/obstacles/winter_tree_4.png");
     m_context->m_assets->loadTexture(OBSTACLE_5,"assets/sprites/obstacles/winter_tree_5.png");
     m_context->m_assets->loadSound(JUMP_SOUND, "assets/sounds/jump.wav");
     m_gameMusic.openFromFile("assets/music/game_music.ogg");

    //  Obstacles Setup
    m_obstacles[0].setTexture(m_context->m_assets->getTexture(OBSTACLE_1));
    m_obstacles[1].setTexture(m_context->m_assets->getTexture(OBSTACLE_2));
    m_obstacles[2].setTexture(m_context->m_assets->getTexture(OBSTACLE_3));
    m_obstacles[3].setTexture(m_context->m_assets->getTexture(OBSTACLE_4));
    m_obstacles[4].setTexture(m_context->m_assets->getTexture(OBSTACLE_5));

   
    // m_obstacles[0].setColor(sf::Color(169,65,6));
    for (size_t i = 0; i < 5; i++)
    { 
         m_obstacles[i].setPosition(m_context->m_window->getSize().x+m_obstacles[i].getGlobalBounds().width,m_context->m_window->getSize().y-64-110);
        /* code */  m_obstacles[i].setScale(1.5,0.9);
    }
    
  
    //Jump Sound Setup
     m_jumpSound.setBuffer(m_context->m_assets->getSound(JUMP_SOUND));
     m_jumpSound.setVolume(30);
    
    //  In Game Music Setup
     m_gameMusic.setLoop(true);
     m_gameMusic.setVolume(50);
    //  TODO: Uncomment this
    //  m_gameMusic.play();

    // TODO:: ADD PARALLAX BACKGROUND

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
   
    m_dino.scale(4.f,4.f);

    
     
 }
 void GamePlay::Update(sf::Time deltaTime) {
    
    if(!m_isPaused)
{
     //  Jumping Mechanics
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

    // If you are jumping, play the jump sound
    if(m_playJumpSound)
    {
        m_jumpSound.play();
        m_playJumpSound = false;
    }

    // Random Obstacle Spawning and moving towards the left
   
   
    for(int i = 0; i < 5; i++)
    {
        m_obstacles[i].move(-5.f,0.f);
        if(m_obstacles[i].getPosition().x < -m_obstacles[i].getGlobalBounds().width)
        {
            m_obstacles[i].setPosition(m_context->m_window->getSize().x+m_obstacles[i].getGlobalBounds().width,m_context->m_window->getSize().y-64-110);
        }
    }


    // Move the floors
    for(int i = 0; i < 24; i++)
    {
        m_floors[i].move(-5.f,0.f);
        if(m_floors[i].getPosition().x < -m_floors[i].getGlobalBounds().width)
        {
            m_floors[i].setPosition(m_context->m_window->getSize().x+m_floors[i].getGlobalBounds().width,m_context->m_window->getSize().y-64);
        }
    }
  
    //  Collision Detection
    for(int i = 0; i < 5; i++)
    {
        if(m_dino.getGlobalBounds().intersects(m_obstacles[i].getGlobalBounds()))
        {
            m_isPaused = true;
           m_context->m_state->AddState(std::make_unique<GameOver>(m_context),false);
        }
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
               
               m_isPaused = !m_isPaused;
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
     for (auto &obstacle : m_obstacles)
     {
         m_context->m_window->draw(obstacle);
     }
   
   
     m_context->m_window->display();
     
 }
 void GamePlay::Pause() {
     m_isPaused = true;
     m_gameMusic.pause();
 }
 void GamePlay::Start() {
        m_isPaused = false;
    //  m_gameMusic.play();
 }
