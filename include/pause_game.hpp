#pragma once

#include "State.hpp"
#include "game.hpp"
#include <SFML/Graphics/Text.hpp>
#include <memory>

class PauseGame : public engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

public:
    PauseGame(std::shared_ptr<Context>& context);
    ~PauseGame();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};