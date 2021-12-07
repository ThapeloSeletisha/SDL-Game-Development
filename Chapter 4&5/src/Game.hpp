#pragma once
#include <iostream>
#include <vector> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameStateMachine.hpp"
#include "MenuState.hpp"

class Game 
{
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    int m_currentFrame;

    bool m_running;

    std::vector<GameObject*> m_gameObjects;
    GameStateMachine* m_pGameStateMachine;

    Game();
    static Game* s_pInstance;
public:
    ~Game();
    static Game* Instance();
    bool init(const char* title, int x, int y, int w, int h, bool fullscreen);
    void render();
    void handleEvents();
    void update();
    void clean();
    void quit();

    SDL_Renderer* getRenderer() const;
    bool running();

    GameStateMachine* getStateMachine();
};

typedef Game TheGame;