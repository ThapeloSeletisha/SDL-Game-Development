#pragma once
#include "GameState.hpp"
#include "Game.hpp"
#include "PlayState.hpp"
#include "AnimatedGraphic.hpp"

class GameObject;

using namespace std;

class GameOverState : public GameState
{
private:
    static void s_gameOverToMain();
    static void s_restartPlay();

    static const game_state s_gameOverID;
    vector<GameObject*> m_gameObjects;

public:
    GameOverState(){};
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual game_state getStateID() const;
};