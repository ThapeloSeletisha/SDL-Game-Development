#pragma once
#include "SDLGameObject.hpp"

class Player : public SDLGameObject 
{ 
public:
    Player(const ParamsLoader* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};