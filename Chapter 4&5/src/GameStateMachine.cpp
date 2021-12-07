#include "GameStateMachine.hpp"

void GameStateMachine::pushState(GameState *pState)
{
    m_gameStates.push(pState);
    m_gameStates.top()->onEnter();
}

void GameStateMachine::popState()
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.top()->onExit())
        {
            delete m_gameStates.top();
            m_gameStates.pop();
        }
    }
}

void GameStateMachine::changeState(GameState *pState)
{
    if (!m_gameStates.empty())
    {
        // "New" state is the same as the current state 
        if (m_gameStates.top()->getStateID() == 
            pState->getStateID())
        {
            return;
        }
        // New State is different from current state
        popState();
    }

    // Push the new state as to become the current state
    m_gameStates.push(pState);
    m_gameStates.top()->onEnter();
}

void GameStateMachine::update()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.top()->update();
    }
}
void GameStateMachine::render()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.top()->render();
    }
}
