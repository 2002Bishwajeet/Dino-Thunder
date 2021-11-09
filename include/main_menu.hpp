#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "game.hpp"

class MainMenu : public engine::State
{

private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gametitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;


    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    virtual void Init() override;
    virtual void ProcessInput() override;
    virtual void Update(sf::Time deltaTime) override;
    virtual void Draw() override;
};