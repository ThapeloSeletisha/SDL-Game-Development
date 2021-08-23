#include "TextureManager.hpp"

TextureManager* TextureManager::s_pInstance = 0;

// Loads and creates a new texture
bool TextureManager::load
     (string fileName,string id,
      SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(!pTempSurface)
    {
        // Temporary surface creation failed
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface
                            (pRenderer, pTempSurface);
    if(!pTexture)
    {
        // Texture creation unsuccessful
        return false;
    }
    SDL_FreeSurface(pTempSurface);

    // Texture creation successful
    // Add texture to list
    m_textureMap[id] = pTexture;
    return true;
}

// Renders the texture associated with the given id
// For rendering the whole image
void TextureManager::draw
     (string id, int x, int y, int
      width, int height, SDL_Renderer* pRenderer,
      SDL_RendererFlip flip)
{
    // Define then initialize the texture's rectangles
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    // Copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], 
                     &srcRect, &destRect, 0, 0, flip);
}

// Renders the texture associated with the given id
// For rendering a frame or sprite 
void TextureManager::drawFrame
     (std::string id, int x, int y, 
      int width, int height, int currentRow, int currentFrame, 
      SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    // Obtain the renderer dimensions
    int w;
    SDL_GetRendererOutputSize(pRenderer,
                              &w, nullptr);

    // Define and initialize the texture's rectangles
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * ((currentFrame) % 6);
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    // Allows texture to move across the window 
    // when drawFrame is called with the arg flip as
    // SDL_FLIP_HORIZONTAL
    if (flip == SDL_FLIP_HORIZONTAL)
    {
        // destRect.x = w - int(currentFrame * 1.3) % (w + srcRect.w);
    }
    else 
    {
        // destRect.x = (int(currentFrame * 1.3) % (w + srcRect.w)) - srcRect.w;
    } 
    destRect.x = x;
    destRect.y = y;

    // Copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
    &destRect, 0, 0, flip);
}