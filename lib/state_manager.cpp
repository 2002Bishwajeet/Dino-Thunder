#include <state_manager.hpp>

engine::StateManager::StateManager() : m_add(false), m_remove(false), m_replace(false)
{
}

engine::StateManager::~StateManager()
{
}

void engine::StateManager::AddState(std::unique_ptr<State> state, bool replace)
{
    m_add = true;
    m_newState = std::move(state);

    m_replace = replace;
}
void engine::StateManager::Popcurrent()
{
    m_remove = true;
}
void engine::StateManager::ProcessStateChange()
{
    if (m_remove && !m_stateStack.empty())
    {
        m_stateStack.pop();
        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Start();
        }
        m_remove = false;
    }

    if (m_add)
    {
        if (!m_stateStack.empty() && m_replace)
        {
            m_stateStack.pop();
        }

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Pause();
        }

        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Start();
        m_add = false;
    }
}
std::unique_ptr<engine::State> &engine::StateManager::GetCurrentState()
{
    return m_stateStack.top();
}