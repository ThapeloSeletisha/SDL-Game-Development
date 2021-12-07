#include "ParamsLoader.hpp"

ParamsLoader::ParamsLoader(int x, int y, 
                           int width, int height,
                           std::string textureID)
                           : m_x(x), m_y(y), 
                           m_width(width), m_height(height),
                           m_textureID(textureID)
{

}

int ParamsLoader::getX() const
{
    return m_x;
}

int ParamsLoader::getY() const
{
    return m_y;
}

int ParamsLoader::getWidth() const
{
    return m_width;
}

int ParamsLoader::getHeight() const
{
    return m_height;
}

std::string ParamsLoader::getTextureID() const
{
    return m_textureID;
}