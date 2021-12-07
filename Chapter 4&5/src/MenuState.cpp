#include "MenuState.hpp"
#include "PlayState.hpp"

const game_state MenuState::s_menuID = MENU;

game_state MenuState::getStateID() const
{
    return s_menuID;
}

void MenuState::update()
{
    for (auto obj: m_gameObjects)
    {
        obj->update();
    }
}

void MenuState::render()
{
    for (auto obj: m_gameObjects)
    {
        obj->draw();
    }
}

bool MenuState::onEnter()
{
    if(!TheTextureManager::Instance()->load(
        "assets/play.png",
        "playButton",
        TheGame::Instance()->getRenderer()
    ))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load(
        "assets/exit.png",
        "exitButton",
        TheGame::Instance()->getRenderer()
    ))
    {
        return false;
    }

    GameObject* playButton = new MenuButton(
        new ParamsLoader(100, 100, 400, 100,
                         "playButton"),
                         s_menuToPlay);
    GameObject* exitButton = new MenuButton(
        new ParamsLoader(100, 300, 400, 100,
                         "exitButton"),
                         s_exitFromMenu);
    
    m_gameObjects.push_back(playButton);
    m_gameObjects.push_back(exitButton);

    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    for (auto obj : m_gameObjects)
    {
        obj->clean();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()
        ->clearFromTextureMap("playButton");
    TheTextureManager::Instance()
        ->clearFromTextureMap("exitButton");
    
    cout << "exiting MenuState" << endl;
    return true;
}

void MenuState::s_menuToPlay()
{
    TheGame::Instance()->getStateMachine()
        ->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->quit();
}

