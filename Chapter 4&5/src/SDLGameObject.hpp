#pragma once
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Vector2D.hpp"

class SDLGameObject : public GameObject
{
protected:

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width, m_height;

    int m_currentRow,
        m_currentFrame;

    std::string m_textureID;

public:
    SDLGameObject(const ParamsLoader* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

    Vector2D& getPosition();
    int getWidth();
    int getHeight();
};