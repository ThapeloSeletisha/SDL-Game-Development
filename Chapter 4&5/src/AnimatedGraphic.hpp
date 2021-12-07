#pragma once
#include "SDLGameObject.hpp"

class AnimatedGraphic : public SDLGameObject
{
private:
    int m_animSpeed;
    int m_numFrames;
    
public:
    AnimatedGraphic(const ParamsLoader* pParams, 
               int animSpeed);

    virtual void draw();
    virtual void update();
    virtual void clean();
};