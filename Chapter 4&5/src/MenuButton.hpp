#pragma once
#include "SDLGameObject.hpp"
#include "button_state.hpp"
#include "InputHandler.hpp"

class MenuButton : public SDLGameObject
{
private:
    void (*m_callback)();
    bool m_bReleased;

public:

    MenuButton(const ParamsLoader* pParams, 
               void (*callback)());

    virtual void draw();
    virtual void update();
    virtual void clean();

};