#include "game_play.hpp"
#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : m_context(context)
{
}

GamePlay::~GamePlay()
{
}


 void GamePlay::Init() {
     
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
     
 }
 void GamePlay::Pause() {
     
 }
 void GamePlay::Start() {
     
 }
