#include "InputHandler.hpp"

const int m_analogStickDeadZone = 2000;
InputHandler* InputHandler::s_pInstance = nullptr;

InputHandler::InputHandler()
{
    for (int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
    m_mousePostion = new Vector2D(-1, -1);
    m_keyboardState = nullptr;
}

InputHandler::~InputHandler()
{
    // Leave empty
}

InputHandler* InputHandler::Instance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new InputHandler();
    }

    return s_pInstance;
}

bool InputHandler::controllersInitialised()
{
    return m_bControllersInitialised;
}

void InputHandler::initialiseControllers()
{
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
    {
        SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    }

    if (SDL_NumJoysticks() > 0)
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_GameController* controller = SDL_GameControllerOpen(i);
            if (controller)
            {
                m_controllers.push_back(controller);
                m_controllerValues.push_back(make_pair(
                    new Vector2D(0, 0), new Vector2D(0, 0)
                ));

                vector<bool> tempButtons;
                for (int j = 0; j < SDL_CONTROLLER_BUTTON_MAX; j++)
                {
                    tempButtons.push_back(false);
                }
                m_controllerButtonStates.push_back(tempButtons);

            }
            else 
            {
                cout << SDL_GetError() << endl;
            }
        }
        SDL_GameControllerEventState(SDL_ENABLE);
        m_bControllersInitialised = true;

        cout << "Initialised " <<  m_controllers.size() << 
                " controller(s)" << endl;        
    }
    else 
    {
        m_bControllersInitialised = false;
    }
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        m_keyboardState = const_cast<Uint8*>
            (SDL_GetKeyboardState(nullptr));
        switch(event.type)
        {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;

        case SDL_CONTROLLERAXISMOTION:
            onControllerAxis(event);
            break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;

        case SDL_CONTROLLERBUTTONDOWN:
            onControllerButtonDown(event);
            break;

        case SDL_CONTROLLERBUTTONUP:
            onCOntrollerButtonUp(event);
            break;

        default:
            break;
        }
        
    }
}

void InputHandler::onControllerAxis(SDL_Event& event)
{
    // The controller number of the controller responsible
    // for the event
    int whichOne = event.caxis.which;

    // The axis number of the controller event
    Uint8 axis = event.caxis.axis;

    // The degree to which the analog stick was pushed
    // Its range is [-32768, 36767] in SDL2.0
    Sint16 value = event.caxis.value;

    if (axis == SDL_CONTROLLER_AXIS_LEFTX)
    {
        // Left anolog stick pushed right 
        if (value > m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].first->setX(1);
        }
        // Left analog stick pushed left
        else if (value < -m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].first->setX(-1);
        }
        // Left analog stick in deadzone
        else
        {
            m_controllerValues[whichOne].first->setX(0);
        }
    }
    
    if(axis == SDL_CONTROLLER_AXIS_LEFTY)
    {
        // Left analog stick pushed up
        if (value > m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].first->setY(1);
        }
        // Left analog stick pushed down
        else if (value < -m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].first->setY(-1);
        }
        // Left analog stick in deadzone
        else
        {
            m_controllerValues[whichOne].first->setY(0);
        }
    }
    
    if (axis == SDL_CONTROLLER_AXIS_RIGHTX)
    {
        // Right analog stick pushed right
        if (value > m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].second->setX(1);                
        }
        // Right analog stick pushed left
        else if (value < -m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].second->setX(-1);
        }
        // Right analog stick in deadzone
        else 
        {
            m_controllerValues[whichOne].second->setX(0);
        }
    }
    
    if (axis == SDL_CONTROLLER_AXIS_RIGHTY)
    {
        // Right analog stick pushed up
        if (value > m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].second->setY(1);
        }
        // Right analog stick pushed down
        else if (value < -m_analogStickDeadZone)
        {
            m_controllerValues[whichOne].second->setY(-1);
        }
        // Right analog stick in deadzone
        else 
        {
            m_controllerValues[whichOne].second->setY(0);
        }
    }
}

// Sets the bool in the m_mouseButtonState that
// corresponds to the mouse click that happened to true
void InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

// Sets the bool in the m_mouseButtonState array that
// corresponds to the mouse button release
// that happened to false
void InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

// Updates the m_mousePosition when
// mouse moves
void InputHandler::onMouseMove(SDL_Event& event)
{
    m_mousePostion->setX(event.motion.x);
    m_mousePostion->setY(event.motion.y);
}

// Sets the bool value in the m_controllerButtonStates array
// that corresponds to the controller button clicked to true
void InputHandler::onControllerButtonDown(SDL_Event& event)
{
    int whichOne = event.caxis.which;
    m_controllerButtonStates[whichOne]
        [event.cbutton.button] = true;
}

// Sets the bool value in the m_controllerButtonStates array
// that corresponds to the controller button released to false
void InputHandler::onCOntrollerButtonUp(SDL_Event& event)
{
    int whichOne = event.caxis.which;
    m_controllerButtonStates[whichOne]
        [event.cbutton.button] = false;
}

void InputHandler::clean()
{
    if (m_bControllersInitialised)
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_GameControllerClose(m_controllers[i]);
        }
    }
}

// Returns the x-axis value for a controller's analog stick
// Takes in the controller number (counts from 0)
// Takes in the analog stick number (counts from 1)
int InputHandler::xvalue(int joy, int stick)
{
    if (m_controllerValues.size() > 0)
    {
        if (stick == 1)
        {
            return m_controllerValues[joy].first->getX();
        }
        else if (stick == 2)
        {
            return m_controllerValues[joy].second->getX();
        }
    }
    return 0;
}
// Returns the y-axis value for a controller's analog stick
// Takes in the controller number (counts from 0)
// Takes in the analog stick number (counts from 1)
int InputHandler::yvalue(int controller, int stick)
{
    if (m_controllerValues.size() > 0)
    {
        if (stick == 1)
        {
            return m_controllerValues[controller].first->getY();
        }
        else if (stick == 2)
        {
            return m_controllerValues[controller].second->getY();
        }
    }
    return 0;
}

// Returns true if the mouse button corresponding to the given
// button number is pressed and false eitherwise
bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePostion()
{
    return m_mousePostion;
}

// Returns true if the controller button corresponding to the 
// given button number and controller is pressed and false eitherwise
bool InputHandler::getControllerButtonState(int controller,
    int buttonNumber)
{
    return m_controllerButtonStates[controller]
        [buttonNumber];
}

// returns true if the specified key is pressed
// and false eitherwise
bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keyboardState != nullptr)
    {
        if (m_keyboardState[key] == 1)
        {
            return true;
        }
    }
    return false;
}