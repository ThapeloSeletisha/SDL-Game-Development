#include "GameOverState.hpp"

const game_state GameOverState::s_gameOverID = GAMEOVER;

void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()
        ->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()
        ->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
    if(!TheTextureManager::Instance()->load("assets/gameover.png",
    "gameovertext", TheGame::Instance()->getRenderer()))
    {
        cout << "gameover.png couldnt be accessed" << endl;
        return false;
    }
    if(!TheTextureManager::Instance()->load("assets/main.png",
    "mainbutton", TheGame::Instance()->getRenderer()))
    {
        cout << "mainbutton.png couldnt be accessed" << endl;
        return false;
    }
    if(!TheTextureManager::Instance()->load("assets/restart.png",
    "restartbutton", TheGame::Instance()->getRenderer()))
    {
        cout << "restartbutton.png couldnt be accessed" << endl;
        return false;
    }
    GameObject* gameOverText = new AnimatedGraphic(
        new ParamsLoader(200, 100, 190, 30, 
        "gameovertext"), 2);
    GameObject* mainButton = new MenuButton(
        new ParamsLoader(200, 200, 200, 80, 
        "mainbutton"), s_gameOverToMain);
    GameObject* restartButton = new MenuButton(
        new ParamsLoader(200, 300, 200, 80, 
        "restartbutton"), s_restartPlay);
    
    m_gameObjects.push_back(gameOverText);
    m_gameObjects.push_back(mainButton);
    m_gameObjects.push_back(restartButton);

    cout << "entering GameOverState" << endl;
    return true;
}

bool GameOverState::onExit()
{
    for (auto obj : m_gameObjects)
    {
        obj->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()
        ->clearFromTextureMap("gameovertext");
    TheTextureManager::Instance()
        ->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()
        ->clearFromTextureMap("restartbutton");

    cout << "exiting GameOverState" << endl;
    return true;

}

game_state GameOverState::getStateID() const
{
    return s_gameOverID;
}

void GameOverState::update()
{
    if (TheInputHandler::Instance()
        ->isKeyDown(SDL_SCANCODE_RETURN))
    {
        TheGame::Instance()->getStateMachine()
            ->pushState(new PauseState());
    }
    for (auto obj : m_gameObjects)
    {
        obj->update();
    }
}

void GameOverState::render()
{
    for (auto obj : m_gameObjects)
    {
        obj->draw();
    }
}