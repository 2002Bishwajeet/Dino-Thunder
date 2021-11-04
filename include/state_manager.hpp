#pragma once

#include <stack>
#include <memory>

#include <State.hpp>

namespace engine
{
    
class StateManager
{
private:

    std::stack<std::unique_ptr<State>> m_stateStack;
    std::unique_ptr<State> m_newState;

    bool m_add;
    bool m_replace;
    bool m_remove;
    /* data */
public:
    StateManager(/* args */);
    ~StateManager();

    void AddState(std::unique_ptr<State> state, bool replace = false);
    void Popcurrent();
    void ProcessStateChange();
    std::unique_ptr<State> &GetCurrentState();
};
}
// namespace engine