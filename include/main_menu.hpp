#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "game.hpp"
#include <array>

//  Main menu Class . As main menu is a state, it has inherited from State class.
class MainMenu : public engine::State
{
private:
    // Shared pointer to the context
    std::shared_ptr<Context> m_context;

    //  Texts
    sf::Text m_gametitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;
    sf::ConvexShape tempcloud;

    // Cloud
    std::array<sf::Sprite, 5> m_clouds;

    //  Music
    sf::Music m_music;

    // Background
    sf::Sprite m_background;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:
    MainMenu(std::shared_ptr<Context>& context);
    ~MainMenu();

    //  Copied all the functions of state to MainMenu class and overrided so that it can be used in main menu
    //  We will be defining the functions in main menu cpp file
    //  Since main menu will not be a derived class now, no need to add virtual anymore
    //  Also Override is though optional, its better to use Override keyword
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};