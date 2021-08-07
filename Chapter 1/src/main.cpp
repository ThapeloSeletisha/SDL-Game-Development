#include <iostream>
#include "Game.hpp"

using namespace std;

int main(int argc, char* args[])
{
    //Create a new game
    Game* game = new Game();

    //Initialize the game
    if(game->init("Chapter 1: Setting up SDL", 350, 150, 640, 480, 0))
    {
        //Game initialization successful
        //This is loop to keep the game going
        while (game->running())
        {
            game->handleEvents();
            game->update();
            game->draw();
        }

        //This cleans up the game resources
        game->clean();
    }
    else 
    {
        cout << "Game initialization unsuccessful" << endl;
    }

    return 0;
}