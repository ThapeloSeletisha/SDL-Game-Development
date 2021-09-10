#pragma once
#include "SDLGameObject.hpp"

class Enemy : public SDLGameObject
{    
public:
    Enemy(const ParamsLoader* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

};