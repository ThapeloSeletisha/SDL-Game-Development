#pragma once
#include "SDLGameObject.hpp"
#include "InputHandler.hpp"

class Player : public SDLGameObject 
{ 
private:
    void handleInput();
public:
    Player(const ParamsLoader* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};