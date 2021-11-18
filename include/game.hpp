#pragma once

#include "asset_manager.hpp"
#include "state_manager.hpp"

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

enum AssetID
{
    MAIN_FONT,
    SECONDARY_FONT,
    CLOUD,
    DINO,
    OBSTACLE_1,
    OBSTACLE_2,
    OBSTACLE_3,
    OBSTACLE_4,
    OBSTACLE_5,
    BIRD,
    BACKGROUND,
    FLOOR,
    JUMP_SOUND,
    GAME_OVER_SOUND

};

//  Context Struct
//  Holds all the data needed to run the game
//  Hold assetManager State manager and Rendering Window

//  We will pass an object to each of the states so that they can access the assets and draw on the window
struct Context
{
    //  They will all hold the unique Pointer
    std::unique_ptr<engine::AssetManager> m_assets;
    std::unique_ptr<engine::StateManager> m_state;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        // Initialize all the pointers
        m_assets = std::make_unique<engine::AssetManager>();
        m_state = std::make_unique<engine::StateManager>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

//  Game Class
class Game
{
private:
    //  creating a shared pointer to the context
    //  To know more about shared pointers check the link below
    //  https://en.cppreference.com/w/cpp/memory/shared_ptr
    //  https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170 -> More Stuff with better examples

    //  To Explain in breif
    /*
        shared_ptr is a smart pointer that manages the lifetime of an object.
        It is a pointer to an object that is shared between multiple owners.
        A shared_ptr can share ownership of an object while storing a pointer to another object.
        This feature can be used to point to member objects while owning the object they belong to.
        The stored pointer is the one accessed by get(), the dereference and the comparison operators.
        The managed pointer is the one passed to the deleter when use count reaches zero.
     */

    std::shared_ptr<Context> m_context;

    //  A variable Time per second is used to calculate the delta time

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    Game();
    ~Game();

    //  Run method to run the game
    void Run();
};
