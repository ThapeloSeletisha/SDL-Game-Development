#include "Enemy.hpp"

void Enemy::load(int x, int y, int width, int height,
                 std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Enemy::update()
{
    m_x++;
    m_y++;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
    // Not implemented
}