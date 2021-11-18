#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

//  A class that manages the state of the game.
//  Consider states as a stack of states.
//  So for this we would be including <stack> header file.

namespace engine
{
    class StateManager
    {
    private:
        // A stack of states.
        //  So a stack variable named m_stateStack created which contains unique pointer to state.
        //  To use unique_ptr we need to include <memory> header file.
        //  To know more about unique_ptr go to:
        //  https://en.cppreference.com/w/cpp/memory/unique_ptr

        // In short unique_ptr is a smart pointer that manages ownership of an object through a pointer.
        // It is used to store a pointer to an object and destroys that object when the unique_ptr goes out of scope.

        std::stack<std::unique_ptr<State>> m_stateStack;

        //  We need a unique_ptr to add a new state to the stack.
        //  This is because we don't want to push a new state when the previous state is being execut
        //  we will add this only after the previous state is complete
        std::unique_ptr<State> m_newState;

        //  These members will be modified by add and popcurrent Methods
        //  and depending on the values the processStateChange will make modifications
        //  to the state stack.
        bool m_add;
        bool m_replace;
        bool m_remove;
        /* data */
    public:
        StateManager();
        ~StateManager();

        //  This function will be used to add a new state to the stack.
        //  This takes a unique_ptr to a state as a parameter and boolean function to determine if the state should be replaced or pushed to the stack
        //  Default will be false
        void AddState(std::unique_ptr<State> state, bool replace = false);

        //  This function will be used to remove a state from the stack.
        void Popcurrent();

        //  THis is the function where the current state will be modified
        void ProcessStateChange();

        //  This is a method which will return the unique pointer
        std::unique_ptr<State>& GetCurrentState();
    };
}
// namespace engine