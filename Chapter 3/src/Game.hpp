#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.hpp"

class Game 
{
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    int m_currentFrame;
    TextureManager *m_textureManager;

    bool m_running;

public:
    Game();
    ~Game();
    bool init(const char* title, int x, int y, int w, int h, bool fullscreen);
    void render();
    void handleEvents();
    void update();
    void clean();
    bool running();
};