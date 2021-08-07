#pragma once
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class Game 
{
private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    bool m_running;

public:
    Game();
    ~Game();
    bool init(const char* title, int x, int y, int w, int h, bool fullscreen);
    void draw();
    void handleEvents();
    void update();
    void clean();
    bool running();
};