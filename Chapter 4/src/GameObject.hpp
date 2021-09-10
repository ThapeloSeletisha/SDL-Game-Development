#pragma once
#include "ParamsLoader.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class GameObject 
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:
    GameObject(const ParamsLoader* pParams);
virtual ~GameObject() {};
};