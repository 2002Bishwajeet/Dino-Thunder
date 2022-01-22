#pragma once

#include "Game.hpp"
#include "State.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <array>
#include <memory>
#include <vector>

class GamePlay : public engine::State
{
private:
    std::shared_ptr<Context> m_context;

    // Background
    sf::Sprite m_sky;

    // Clouds
    sf::Sprite m_cloud;
    sf::Shader m_shaderCloud;
    float cloud_offset = 0.f;

    // Mountains
    sf::Sprite m_mountains;
    sf::Shader m_shaderMountain;
    float mountain_offset = 0.f;

    // Pine 1
    sf::Sprite m_pine1;
    sf::Shader m_shaderPine1;
    float pine1_offset = 0.f;

    // Pine 2
    sf::Sprite m_pine2;
    sf::Shader m_shaderPine2;
    float pine2_offset = 0.f;

    // Floor
    sf::Sprite m_floor;

    // DINO
    sf::Sprite m_dino;

    // In Game Music
    sf::Music m_gameMusic;

    //  Jump Sound
    sf::Sound m_jumpSound;
    bool m_playJumpSound;

    // Obstacle
    sf::Sprite m_obstacle;

    sf::IntRect m_dinoRect;
    sf::Clock clock;
    sf::Text m_scoreText;

    bool m_isPaused;

    bool m_isJumping;

    // PHYSICS
    // JUMPING SPEED AND GRAVITY VARIABLES
    float m_jumpSpeed;
    float y = 0;
    float x = 0;
    float velocityY = 0;
    float accelerationY = 0;
    float gravity = 1.0f;

    // GAME SPEED
    float m_gameSpeed = 6.0f;

    //  Current Game Score
    float m_score = 0;

public:
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
};