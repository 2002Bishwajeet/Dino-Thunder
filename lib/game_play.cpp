#include "game_play.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context)
{
}

GamePlay::~GamePlay()
{
}


 void GamePlay::Init() {
     m_context->m_assets->loadTexture(BACKGROUND, "assets/sprites/background/layers/parallax-mountain-bg.png");
     m_context->m_assets->loadTexture(MOUNTAINS, "assets/sprites/background/layers/parallax-mountain-mountains.png");

     m_background.setTexture(m_context->m_assets->getTexture(BACKGROUND));
    m_background.setScale(5.f, 5.f);


     m_mountains.setTexture(m_context->m_assets->getTexture(MOUNTAINS));
   m_mountains.setOrigin(m_mountains.getLocalBounds().width/2, m_mountains.getLocalBounds().height/2 );
    m_mountains.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y-80);
    m_mountains.setScale(3.f, 2.f);
    
     
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
     m_context->m_window->draw(m_mountains);
     m_context->m_window->display();
     
 }
 void GamePlay::Pause() {
     
 }
 void GamePlay::Start() {
     
 }
