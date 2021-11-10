#include <state_manager.hpp>

// When a state manager is called we keep the add, remove and replace values to False by default
engine::StateManager::StateManager() : m_add(false), m_remove(false), m_replace(false)
{
}

engine::StateManager::~StateManager()
{
}

// Definition of the add function
void engine::StateManager::AddState(std::unique_ptr<State> state, bool replace)
{
    //  We set the add value to true
    m_add = true;


    // std::move is used to indicate that an object t may be "moved from",
    //  i.e. allowing the efficient transfer of resources from t to another object.
    m_newState = std::move(state);

    // If the replace value is true we set the replace value to true
    m_replace = replace;
}
void engine::StateManager::Popcurrent()
{
    // We set the remove value to true
    m_remove = true;
}
void engine::StateManager::ProcessStateChange()
{
    //  This function is used to process current state Stack
    //  Before performing anything we check if the remove value is true & sthe stack is not empty
    if (m_remove && !m_stateStack.empty())
    {
        m_stateStack.pop();
        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Start();
        }
        //  Resetting it to false
        m_remove = false;
    }

    //  If m_add is true
    if (m_add)
    {
        //  Then check is the stack is not empty and replace true
        if (!m_stateStack.empty() && m_replace)
        {
            m_stateStack.pop();
        }

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Pause();
        }

    // Now perform the neceessary push pop operation of the state
        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Start();
        m_add = false;
    }
}
std::unique_ptr<engine::State> &engine::StateManager::GetCurrentState()
{
    //  Returns a reference to the current state
    return m_stateStack.top();
}