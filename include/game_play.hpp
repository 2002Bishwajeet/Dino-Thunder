#pragma once

#include "State.hpp"
#include "Game.hpp"
#include<memory>


class GamePlay : public engine::State {

    private:
        std::shared_ptr<Context> m_context;

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