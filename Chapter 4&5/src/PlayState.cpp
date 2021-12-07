#include "PlayState.hpp"

const game_state PlayState::s_playID = PLAY;

game_state PlayState::getStateID() const
{
    return s_playID;
}

void PlayState::update()
{
    if (TheInputHandler::Instance()
        ->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()
            ->pushState(new PauseState());
    }
    for (auto obj : m_gameObjects)
    {
        obj->update();
    }
    if(collision(dynamic_cast<SDLGameObject*> (m_gameObjects[0]), 
        dynamic_cast<SDLGameObject*> (m_gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->changeState(
            new GameOverState());
    }
}

void PlayState::render()
{
    for (auto obj : m_gameObjects)
    {
        obj->draw();
    }
}

bool PlayState::onEnter()
{
    if(!TheTextureManager::Instance()->load(
        "assets/helicopter1.png",
        "helicopter1", 
        TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load(
        "assets/helicopter2.png",
        "helicopter2", 
        TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* player = new Player(
        new ParamsLoader(500, 100, 128, 55, 
        "helicopter1"));
    GameObject* enemy = new Enemy(
        new ParamsLoader(100, 100, 128, 55, 
        "helicopter2"));

    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);
    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()
        ->clearFromTextureMap("helicopter1");
    TheTextureManager::Instance()
        ->clearFromTextureMap("helicopter2");
    
    cout << "exiting PlayState" << endl;
    return true;
}

bool PlayState::collision(SDLGameObject* obj1, 
    SDLGameObject* obj2)
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

    left1 = obj1->getPosition().getX();
    right1 = obj1->getPosition().getX() + obj1->getWidth();
    top1 = obj1->getPosition().getY();
    bottom1 = obj1->getPosition().getY() + obj1->getHeight();
    
    //Calculate the sides of rect B
    left2 = obj2->getPosition().getX();
    right2 = obj2->getPosition().getX() + obj2->getWidth();
    top2 = obj2->getPosition().getY();
    bottom2 = obj2->getPosition().getY() + obj2->getHeight();
    
    //If any of the sides from A are outside of B
    if( bottom1 <= top2 ){return false;}
    if( top1 >= bottom2 ){return false;}
    if( right1 <= left2 ){return false;}
    if( left1 >= right2 ){return false;}
    
    return true;
}
