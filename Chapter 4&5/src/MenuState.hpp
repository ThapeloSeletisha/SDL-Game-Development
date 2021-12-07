#pragma once
#include "GameState.hpp"
#include "MenuButton.hpp"

using namespace std; 

class MenuState: public GameState
{
private:
    static const game_state s_menuID;
    vector<GameObject*> m_gameObjects;

    static void s_menuToPlay();
    static void s_exitFromMenu();

public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual game_state getStateID() const;
};