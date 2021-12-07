#include <iostream>
#include "Game.hpp"
using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
    Uint32 frameStart, frameTime;

    cout << "game init attempt..." << endl;

    if(TheGame::Instance()->init("Chapter 1: Setting up SDL", 350, 150, 640, 480, 0))
    {
        //Game initialization successful
        //This is loop to keep the game going
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int) (DELAY_TIME - frameTime));
            }
        }
    }
    else 
    {
        cout << "Game initialization unsuccessful" << endl;
        return -1;
    }

    //This cleans up the game resources
    cout << "game closing..." << endl;
    TheGame::Instance()->clean();

    return 0;
}