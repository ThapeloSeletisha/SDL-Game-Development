#include "MenuButton.hpp"

MenuButton::MenuButton(const ParamsLoader* pParams,
            void (*callback)()) : 
            SDLGameObject (pParams),
            m_callback(callback)
{
    m_currentFrame = MOUSE_OUT;
    m_bReleased = true;
}

void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::update()
{
    Vector2D* pMousePos = TheInputHandler::Instance()
            ->getMousePostion();
    if(pMousePos->getX() < (m_position.getX() + m_width)
       && pMousePos->getX() > m_position.getX()
       && pMousePos->getY() < (m_position.getY() + m_height)
       && pMousePos->getY() > m_position.getY())
    {
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT)
           && m_bReleased)
        {
            m_currentFrame = CLICKED;
            m_callback();
            m_bReleased = false;
        }
        else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}

