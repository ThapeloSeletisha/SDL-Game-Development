#pragma once
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class GameObject 
{
public:
    void load(int x, int y, int width, int height, 
              std::string textureID);

    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();

protected:
    std::string m_textureID;

    int m_currentFrame, 
        m_currentRow;

    int m_x, m_y;

    int m_width, m_height;
};