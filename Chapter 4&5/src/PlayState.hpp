#pragma once
#include "GameState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class PlayState : public GameState
{
private:
    static const game_state s_playID;
    vector<GameObject*> m_gameObjects;

    bool collision(SDLGameObject* obj1, 
        SDLGameObject* obj2);

public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual game_state getStateID() const;
};
