#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height,
              std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};