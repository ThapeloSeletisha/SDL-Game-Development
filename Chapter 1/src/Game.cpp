#include "Game.hpp"

Game::Game()
{
    m_running = true;
    m_Renderer = nullptr;
    m_Window = nullptr;
}
//Initializes the game and ints variables
//Returns true if everything is successful and false otherwise
bool Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
    //Initialize the SDL2 library
    if (!SDL_Init(SDL_INIT_EVERYTHING))
    {
        Uint32 flags;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        else 
        {
            flags = 0;
        }
        //SDL2 initilized successfully
        m_Window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (m_Window)
        {
            //Window creation was successful
            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
            if (m_Renderer)
            {
                //Renderer creation successful
                SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255); 
            }
            else 
            {
                //Renderer creation failed
                cout << "Failed to create renderer" << endl;
                cout << "SDL error: "  << SDL_GetError() << endl;
                return false;
            }
        } 
        else 
        {   
            //Window creation failed 
            cout << "Failed to create window" << endl;
            cout << "SDL error: "  << SDL_GetError() << endl;
            return false;
        }
 
    }
    else 
    {
        //SDL2 initialization failed
        cout << "Failed to initialize SDL" << endl;
        cout << "SDL error: "  << SDL_GetError() << endl;
        return false;
    }
    return true;
}
//Renders the blank window
void Game::draw()
{
    SDL_RenderClear(m_Renderer);
    SDL_RenderPresent(m_Renderer);
}
//Handles any events
void Game::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        //There are events that need handling
        switch(e.type)
        {
            case SDL_QUIT:
                //User exits the game
                m_running = false;
                break;
        }
    }
}
//Cleans the resources used by game class
void Game::clean()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit(); // Free SDL resources
}
//Returns true if the game is still running
bool Game::running()
{
    return m_running;
}
//Updates any game variables that need updating
void Game::update()
{
    //Nothing to update
}