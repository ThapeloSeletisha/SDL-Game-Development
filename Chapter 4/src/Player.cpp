#include "Player.hpp"
#include "Game.hpp"

Player::Player(const ParamsLoader* pParams)
: SDLGameObject(pParams)
{
    m_velocity.setX(0);
    m_acceleration.setX(0);
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    handleInput();
    SDLGameObject::update();
}

void Player::clean()
{
    // Not implemented
}

void Player::handleInput()
{
    m_velocity.setX(0);
    m_velocity.setY(0);
    if(TheInputHandler::Instance()->controllersInitialised())
    {
        // Use the left analog stick on the first controller 
        // m_velocity.setX(TheInputHandler::Instance()->
        //     xvalue(0, 1));
        // m_velocity.setY(TheInputHandler::Instance()->
        //     yvalue(0, 1));

        // Use the right analog stick on the first controller 
        m_velocity.setX(TheInputHandler::Instance()->
            xvalue(0, 2));
        m_velocity.setY(TheInputHandler::Instance()->
            yvalue(0, 2));
        
        // Use controller arrows
        if(TheInputHandler::Instance()->
            getControllerButtonState
            (0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
        {
            m_velocity.setX(1);
        }
        if(TheInputHandler::Instance()->
            getControllerButtonState
            (0, SDL_CONTROLLER_BUTTON_DPAD_LEFT))
        {
            m_velocity.setX(-1);
        }
        if(TheInputHandler::Instance()->
            getControllerButtonState
            (0, SDL_CONTROLLER_BUTTON_DPAD_DOWN))
        {
            m_velocity.setY(1);
        }
        if(TheInputHandler::Instance()->
            getControllerButtonState
            (0, SDL_CONTROLLER_BUTTON_DPAD_UP))
        {
            m_velocity.setY(-1);
        }
    }

    // Use Keyboard arrows
    if(TheInputHandler::Instance()->
        isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(2);
    }
    if(TheInputHandler::Instance()->
        isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-2);
    }
    if(TheInputHandler::Instance()->
        isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-2);
    }
    if(TheInputHandler::Instance()->
        isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(2);
    }
    

}