#pragma once
#include <iostream>

class ParamsLoader
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_textureID;
public:
    ParamsLoader(int x, int y, int width, int height,
                 std::string textureID);
     
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureID() const;
};