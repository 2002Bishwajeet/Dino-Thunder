#include "game_play.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context)
{
}

GamePlay::~GamePlay()
{
}


 void GamePlay::Init() {

     m_context->m_assets->loadTexture(BACKGROUND, "assets/sprites/background/layers/parallax-mountain.png");
     m_context->m_assets->loadTexture(FLOOR, "assets/sprites/floor/Wasteland-Files.png");

    m_background.setTexture(m_context->m_assets->getTexture(BACKGROUND));
    m_background.setScale(5.f, 5.f);

    m_floor.setTexture(m_context->m_assets->getTexture(FLOOR));
    m_floor.setTextureRect(sf::IntRect(100, 128, 16, 16));
    m_floor.setScale(5.f, 4.f);
    
    for (int i = 0; i < 24; i++)
    {

    m_floor.setPosition(i*62.f, m_context->m_window->getSize().y-64 );
    m_floors.push_back(m_floor);
        /* code */
    }
    

    
     
 }
 void GamePlay::Update(sf::Time deltaTime) {
     
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
          
       
         }  
         else if (event.type == sf::Event::KeyPressed)
        {
           
        }
    }
     
 }
 void GamePlay::Draw() {

     m_context->m_window->clear();
     m_context->m_window->draw(m_background);
     for (auto &floor : m_floors)
     {
         m_context->m_window->draw(floor);
     }
     
    //  m_context->m_window->draw(m_floor);
     m_context->m_window->display();
     
 }
 void GamePlay::Pause() {
     
 }
 void GamePlay::Start() {
     
 }
