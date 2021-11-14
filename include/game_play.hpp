#pragma once

#include "State.hpp"
#include "Game.hpp"
#include<memory>
#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/Music.hpp>
#include<vector>

class GamePlay : public engine::State {

    private:
        std::shared_ptr<Context> m_context;
        sf::Sprite m_background;
        sf::Sprite m_floor;
        sf::Sprite m_dino;
        sf::Music m_gameMusic;
        sf::Sound m_jumpSound;
        sf::Sound m_dieSound;
        std::vector<sf::Sprite> m_floors;
        sf::IntRect m_dinoRect;

    public:
    
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();
    
     void Init() override;
     void ProcessInput() override;
     void Update(sf::Time deltaTime) override;
     void Draw() override;
     void Pause() override;
     void Start() override;
};