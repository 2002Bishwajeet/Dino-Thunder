#include "game_play.hpp"
#include "game_over.hpp"
#include <SFML/Window/Event.hpp>
#include "pause_game.hpp"

GamePlay::GamePlay(std::shared_ptr<Context>& context)
    : m_context(context)
    , m_isJumping(false)
    , m_jumpSpeed(25.0)
    , m_playJumpSound(false)
    , m_gameSpeed(6.5f)
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::Init()
{
    //  Loading Assets for the game
    m_context->m_assets->loadTexture(SKY, "assets/sprites/background/sky.png");
    m_context->m_assets->loadTexture(SKY_CLOUD, "assets/sprites/background/sky_cloud.png");
    m_context->m_assets->loadTexture(PINE_1, "assets/sprites/background/pine1.png");
    m_context->m_assets->loadTexture(PINE_2, "assets/sprites/background/pine2.png");
    m_context->m_assets->loadTexture(MOUNTAINS, "assets/sprites/background/mountain2.png");
    m_context->m_assets->loadTexture(CLOUD, "assets/sprites/background/cloud.png");

    m_context->m_assets->loadTexture(FLOOR, "assets/sprites/floor/Wasteland-Files.png");
    m_context->m_assets->loadTexture(DINO, "assets/sprites/Dino/sheets/DinoSprites-tard.png");
    m_context->m_assets->loadTexture(OBSTACLE_1, "assets/sprites/obstacles/winter_tree_1.png");
    m_context->m_assets->loadTexture(OBSTACLE_2, "assets/sprites/obstacles/winter_tree_2.png");
    m_context->m_assets->loadTexture(OBSTACLE_3, "assets/sprites/obstacles/winter_tree_3.png");
    m_context->m_assets->loadTexture(OBSTACLE_4, "assets/sprites/obstacles/winter_tree_4.png");
    m_context->m_assets->loadTexture(OBSTACLE_5, "assets/sprites/obstacles/winter_tree_5.png");
    m_context->m_assets->loadSound(JUMP_SOUND, "assets/sounds/jump.wav");
    m_gameMusic.openFromFile("assets/music/game_music.ogg");

    // Score Text Setup
    m_scoreText.setFont(m_context->m_assets->getFont(SECONDARY_FONT));
    m_scoreText.setCharacterSize(30);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(sf::Vector2f(m_context->m_window->getSize().x - m_scoreText.getGlobalBounds().height - 200, 10));

    //  Obstacles Setup
    m_obstacle.setPosition(0, m_context->m_window->getSize().y + m_obstacle.getGlobalBounds().height);
    m_obstacle.setScale(1.5, 0.9);

    // Jump Sound Setup
    m_jumpSound.setBuffer(m_context->m_assets->getSound(JUMP_SOUND));
    m_jumpSound.setVolume(30);

    //  In Game Music Setup
    m_gameMusic.setLoop(true);
    m_gameMusic.setVolume(50);

    m_gameMusic.play();

    // Background Setup
    m_sky.setTexture(m_context->m_assets->getTexture(SKY));
    m_sky.scale(2.0f, 2.0f);

    m_skyCloud.setTexture(m_context->m_assets->getTexture(SKY_CLOUD));
    m_skyCloud.scale(2.0f, 1.0f);
    m_skyCloud.setPosition(0.0f, 50.0f);

    m_cloud.setTexture(m_context->m_assets->getTexture(CLOUD));
    m_cloud.scale(2.0f, 1.0f);
    m_cloud.setPosition(0.0f, 50.0f);

    m_mountains.setTexture(m_context->m_assets->getTexture(MOUNTAINS));
    m_mountains.scale(2.0f, 2.0f);
    m_mountains.setPosition(0.0f, 230.0f);

    m_pine1.setTexture(m_context->m_assets->getTexture(PINE_1));
    m_pine1.scale(2.0f, 1.5f);
    m_pine1.setPosition(0.0f, 360.0f);

    m_pine2.setTexture(m_context->m_assets->getTexture(PINE_2));
    m_pine2.scale(2.0f, 1.5f);
    m_pine2.setPosition(0.0f, 425.0f);

       // Floor Setup
    m_floor.setTexture(m_context->m_assets->getTexture(FLOOR));
    m_floor.setTextureRect(sf::IntRect(100, 128, 16, 16));
    m_floor.setScale(5.f, 4.f);

    // TODO: Figure out a better way for the loop condition.
    //  What if you decided to increase the window size?
    for (int i = 0; i < 24; i++)
    {
        m_floor.setPosition(i * 62.f, m_context->m_window->getSize().y - 64);
        m_floors.push_back(m_floor);
    }

    // Dino Setup
    m_dinoRect = sf::IntRect(0, 0, 24, 24);
    m_dino.setTexture(m_context->m_assets->getTexture(DINO));
    m_dino.setTextureRect(m_dinoRect);

    m_dino.scale(4.f, 4.f);
}
void GamePlay::Update(sf::Time deltaTime)
{
    if (!m_isPaused)
    {
        //  Jumping Mechanics
        if (y < m_context->m_window->getSize().y - m_floor.getGlobalBounds().height - (22 * 4)) // If you are above ground
        {
            velocityY += gravity; // Add gravity
            m_isJumping = true;
        }
        else if (y > m_context->m_window->getSize().y - m_floor.getGlobalBounds().height - (22 * 4)) // If you are below ground
            y = m_context->m_window->getSize().y - m_floor.getGlobalBounds().height - (22 * 4);      // That's not supposed to happen, put him back up

        if (y == m_context->m_window->getSize().y - m_floor.getGlobalBounds().height - (22 * 4))
            m_isJumping = false;

        // This is useless for now, could be used for a better jump mechanic later
        velocityY += accelerationY;
        m_dino.setPosition(x, y);
        y += velocityY;

        // End of Jumping Mechanics Code

        // If you are jumping, play the jump sound
        if (m_playJumpSound)
        {
            m_jumpSound.play();
            m_playJumpSound = false;
        }

        // Increase score as time passes
        m_score += deltaTime.asSeconds() * m_gameSpeed;
        m_scoreText.setString("Score: " + std::to_string(abs(m_score)));

        if ((int)abs(m_score) % 100 == 0)
            m_gameSpeed += 0.3f;

        // Randomly generate obstacles and move them

        if (m_obstacle.getPosition().x < -m_obstacle.getGlobalBounds().width)
        {
            m_obstacle.setPosition(m_context->m_window->getSize().x + m_obstacle.getGlobalBounds().width, m_context->m_window->getSize().y - 64 - 110);
            m_obstacle.setTexture(m_context->m_assets->getTexture(OBSTACLE_1 + rand() % 5));
        }
        m_obstacle.move(-m_gameSpeed, 0.f);

        // Random Obstacle Spawning and moving towards the left
        // for(int i = 0; i < 5; i++)
        // {
        //     m_obstacles[i].move(-6.f,0.f);

        //     if(m_obstacles[i].getPosition().x < -m_obstacles[i].getGlobalBounds().width)
        //     {
        //         m_obstacles[i].setPosition(m_context->m_window->getSize().x +250 ,m_context->m_window->getSize().y-64-110);
        //     }
        // }

        // Move the floors
        for (int i = 0; i < 24; i++)
        {
            m_floors[i].move(-m_gameSpeed, 0.f);
            if (m_floors[i].getPosition().x < -m_floors[i].getGlobalBounds().width)
            {
                m_floors[i].setPosition(m_context->m_window->getSize().x + m_floors[i].getGlobalBounds().width, m_context->m_window->getSize().y - 64);
            }
        }

        //  Collision Detection
        for (int i = 0; i < 5; i++)
        {
            if (m_dino.getGlobalBounds().intersects(m_obstacle.getGlobalBounds()))
            {
                m_context->m_state->AddState(std::make_unique<GameOver>(m_context), false);
                m_isPaused = true;
            }
        }

        // UPDATE THE DINO ANIMATION
        ////
        /////
        /////
        //////

        if (clock.getElapsedTime().asSeconds() > 0.08f && !m_isJumping)
        {
            if (m_dinoRect.left == 240)
                m_dinoRect.left = 120;
            else
                m_dinoRect.left += 24;

            m_dino.setTextureRect(m_dinoRect);
            clock.restart();
        }
    }
}
void GamePlay::ProcessInput()
{
    //  Event handling
    sf::Event event;

    while (m_context->m_window->pollEvent(event))
    {
        //  Close window
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
            m_gameMusic.stop();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
            {
                if (!m_isJumping)
                {
                    velocityY = -m_jumpSpeed;
                    m_isJumping = true;
                    m_playJumpSound = true;
                    m_dinoRect.left = 0;
                    m_dino.setTextureRect(m_dinoRect);
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                m_context->m_state->AddState(std::make_unique<PauseGame>(m_context));
                m_isPaused = true;
            }
        }
    }
}
void GamePlay::Draw()
{
    m_context->m_window->clear();

    // Drawing Background
    m_context->m_window->draw(m_sky);
    m_context->m_window->draw(m_skyCloud);
    m_context->m_window->draw(m_cloud);
    m_context->m_window->draw(m_mountains);
    m_context->m_window->draw(m_pine1);
    m_context->m_window->draw(m_pine2);

    m_context->m_window->draw(m_dino);

    for (auto& floor : m_floors)
    {
        m_context->m_window->draw(floor);
    }
    m_context->m_window->draw(m_obstacle);
    m_context->m_window->draw(m_scoreText);

    m_context->m_window->display();
}
void GamePlay::Pause()
{
    m_isPaused = !m_isPaused;
    m_gameMusic.pause();
}
void GamePlay::Start()
{
    m_isPaused = false;
    //  m_gameMusic.play();
}
