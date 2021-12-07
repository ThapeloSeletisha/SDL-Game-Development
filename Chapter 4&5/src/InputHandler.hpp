#pragma once
#include "Game.hpp"
#include "Vector2D.hpp"
#include <utility>
#include "mouse_button.hpp"
 
using namespace std;

class InputHandler
{
private:
    InputHandler();
    ~InputHandler();

    static InputHandler* s_pInstance;

    vector<SDL_GameController*> m_controllers;
    // m_joystickValues holds the 2 axes
    // of the 2 joy analog stick of each joystick
    vector<pair<Vector2D*, Vector2D*>> m_controllerValues;
    vector<vector<bool>> m_controllerButtonStates;
    bool m_bControllersInitialised;

    vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePostion;

    Uint8* m_keyboardState;

    // Handle keyboard events
    void onKeyDown();
    void onKeyUp();

    // Handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // Handle controller events
    void onControllerAxis(SDL_Event& event);
    void onControllerButtonDown(SDL_Event& event);
    void onCOntrollerButtonUp(SDL_Event& event);

public:
    static InputHandler* Instance();
    void initialiseControllers();
    bool controllersInitialised();

    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

    void update();
    void clean();

    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePostion();
    void reset();

    bool getControllerButtonState(int controller, 
            int buttonNumber);

    bool isKeyDown(SDL_Scancode key);
};

typedef InputHandler TheInputHandler;