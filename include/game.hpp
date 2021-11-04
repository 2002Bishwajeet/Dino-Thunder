#pragma once

#include "asset_manager.hpp"
#include "state_manager.hpp"

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

struct Context
{
    std::unique_ptr<engine::AssetManager> m_assets;
    std::unique_ptr<engine::StateManager> m_state;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<engine::AssetManager>();
        m_state = std::make_unique<engine::StateManager>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_SECOND = sf::seconds(1.f / 60.f);

public:
    Game(/* args */);
    ~Game();

    void Run();
};
