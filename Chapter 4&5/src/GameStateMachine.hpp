#pragma once
#include <stack>
#include "GameState.hpp"

using namespace std;

class GameStateMachine
{
private:
    stack<GameState*, vector<GameState*> > m_gameStates;

public:
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

    void update();
    void render();
};