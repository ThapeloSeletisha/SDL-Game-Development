#pragma once
#include "GameState.hpp"
#include "Game.hpp"

using namespace std;
class PauseState : public GameState
{
private:
    static void s_pauseToMain();
    static void s_resumePlay();

    static const game_state s_pauseID;

    vector<GameObject*> m_gameObjects;

public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual game_state getStateID() const;
};