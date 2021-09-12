#pragma once
#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class TextureManager
{
private:
    map<string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
    TextureManager() {};
    

public:
    static TextureManager* Instance();
  
    bool load(string fileName,string id,
              SDL_Renderer* pRenderer);

    // draw
    void draw(std::string id, int x, int y, int width, int height, 
              SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // drawframe
    void drawFrame(std::string id, int x, int y, int width, int height, 
                   int currentRow, int currentFrame, SDL_Renderer* pRenderer, 
                   SDL_RendererFlip flip = SDL_FLIP_NONE);

};

typedef TextureManager TheTextureManager;