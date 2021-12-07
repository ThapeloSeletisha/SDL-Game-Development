#include "PauseState.hpp"

const game_state PauseState::s_pauseID = PAUSE;

void PauseState::s_pauseToMain()
{
    TheGame::Instance()->getStateMachine()
        ->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    TheGame::Instance()->getStateMachine()
        ->popState();
}

void PauseState::update()
{
    for (auto obj : m_gameObjects)
    {
        obj->update();
    }
}

void PauseState::render()
{
    for (auto obj : m_gameObjects)
    {
        obj->draw();
    }
}

bool PauseState::onEnter()
{
    if (!TheTextureManager::Instance()->load(
        "assets/resume.png",
        "resumeButton",
        TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load(
        "assets/main.png",
        "mainButton",
        TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* mainButton = new MenuButton(
        new ParamsLoader(200, 200, 200, 80, 
        "mainButton"),
        s_pauseToMain);
    GameObject* resumeButton = new MenuButton(
        new ParamsLoader(200, 300, 200, 80, 
        "resumeButton"),
        s_resumePlay);

    m_gameObjects.push_back(mainButton);
    m_gameObjects.push_back(resumeButton);

    cout << "entering PauseState" << endl;
    return true;
}

bool PauseState::onExit()
{
    for (auto obj : m_gameObjects)
    {
        obj->clean();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()
        ->clearFromTextureMap("resumeButton");
    
    TheTextureManager::Instance()
        ->clearFromTextureMap("mainButton");
    
    TheInputHandler::Instance()->reset();

    cout << "exiting PauseState" << endl;
    return true;
}

game_state PauseState::getStateID() const
{
    return s_pauseID;
}