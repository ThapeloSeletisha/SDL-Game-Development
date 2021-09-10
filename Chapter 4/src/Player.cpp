#include "Player.hpp"
#include "Game.hpp"

Player::Player(const ParamsLoader* pParams)
: SDLGameObject(pParams)
{
    m_velocity.setX(1);
    m_acceleration.setX(0.03);
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    SDLGameObject::update();
}

void Player::clean()
{
    // Not implemented
}