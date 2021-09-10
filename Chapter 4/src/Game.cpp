#include "Game.hpp"
Game* Game::s_pInstance = nullptr;
Game::Game()
{
    m_running = true;
    m_renderer = nullptr;
    m_window = nullptr;
}

Game* Game::Instance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new Game();
        return s_pInstance;
    }
    return s_pInstance;
}

//Initializes the game and ints variables
//Returns true if everything is successful and false otherwise
bool Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
    //Initialize the SDL2 library
    if (!SDL_Init(SDL_INIT_EVERYTHING))
    {
        //SDL2 initilized successfully
        Uint32 flags;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        else 
        {
            flags = 0;
        }
        m_window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (m_window)
        {
            //Window creation was successful
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
            if (m_renderer)
            {
                // Renderer creation successful
                SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255); 
                if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
                                        "animate", m_renderer))
                {
                    // animate texture loading unsuccessfully
                    cout << "Failed to load animate-alpha.png" << endl;
                    cout << "SDL error: "  << SDL_GetError() << endl;
                    return false;
                }

                m_gameObjects.push_back(new Player
                    (new ParamsLoader(0, 100, 128, 82, "animate")));
                m_gameObjects.push_back(new Enemy
                    (new ParamsLoader(300, 300, 128, 82, "animate")));
                
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
void Game::render()
{
    SDL_RenderClear(m_renderer);
    // TheTextureManager::Instance()->draw("animate", 0,0, 128, 82,
    //                        m_renderer);
    // TheTextureManager::Instance()->drawFrame("animate", 100,100, 128, 82,
    //                            1, m_currentFrame, m_renderer, SDL_FLIP_NONE);
    for (size_t i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    SDL_RenderPresent(m_renderer);
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
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
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
    // Change sprite every 100ms
    // m_currentFrame = int((SDL_GetTicks() / 5));

    for (size_t i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}
SDL_Renderer* Game::getRenderer() const
{
    return m_renderer;
}