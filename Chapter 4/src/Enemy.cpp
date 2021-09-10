#include "Enemy.hpp"

Enemy::Enemy(const ParamsLoader* pParams)
: SDLGameObject(pParams)
{
    m_velocity.setX(1);
    m_velocity.setY(1);
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    SDLGameObject::update();
}

void Enemy::clean()
{
    // Not implemented
}