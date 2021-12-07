#pragma once
#include <vector>
#include <iostream>
#include "GameObject.hpp"
#include "game_state.hpp"


class GameState
{
protected:

public:
    GameState(){};
    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual game_state getStateID() const = 0;
};