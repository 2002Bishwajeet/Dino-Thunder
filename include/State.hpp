#pragma once

#include <SFML/System/Time.hpp>

namespace engine
{
    class State
    {
    private:
        /* data */
    public:
        State(){};
        virtual ~State(){};
        virtual void Init() = 0;
        virtual void ProcessInput() = 0;
        virtual void Update(sf::Time deltaTime) = 0;
        virtual void Draw() = 0;

        virtual void Pause(){};
        virtual void Start(){};
    };

} // namespace engine
