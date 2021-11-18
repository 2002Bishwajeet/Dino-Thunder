#pragma once

#include <SFML/System/Time.hpp>

/*
Defining a State Class
A state class is a class that represents a state of the game.
It is responsible for updating the game state and rendering it.
 Since this class would be inherited by other classes, it is abstract.
 so we do not need a cpp file for this class
A header file is sufficient since it would be derived
 */

namespace engine
{
    class State
    {
    public:
        State(){};

        //  All the functions need to be declared as virtual since we are inheriting from this class
        //  This is a pure virtual function
        //  Also we need to declare the destructor as virtual since we are inheriting from this class
        //  Not declaring it would not lead to proper dispose of this class

        /*
        Since this is a state class, we need mainly the 4 functions below
         */

        virtual ~State(){};

        //  All the definations would be provided in the derived class

        //  This function will be called when the state is pushed to the stack
        virtual void Init() = 0;

        //  This function will handle the events like keypress or mouseclicks etc
        virtual void ProcessInput() = 0;

        //  This function will be called every deltaTime(which takes as a parameter) to update the game state like reposition or colors etc
        virtual void Update(sf::Time deltaTime) = 0;

        //  This function will be called to render the game state on the screen
        virtual void Draw() = 0;

        // Apart from that we have two more virtual functions pause and start
        //  This would be required in the mid Game state
        virtual void Pause(){};
        virtual void Start(){};
    };

} // namespace engine
