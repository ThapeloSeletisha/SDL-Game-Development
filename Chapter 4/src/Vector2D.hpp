#pragma once
#include <math.h>

class Vector2D
{
private:
    double m_x, m_y;

public:
    Vector2D(double x, double y);

    double getX();
    double getY();

    void setX(double x);
    void setY(double y);

    double length();

    Vector2D operator+(const Vector2D& v2) const;
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;

        return v1;
    }

    Vector2D operator*(double scalar);
    Vector2D& operator*=(double scalar);

    Vector2D operator-(const Vector2D& v2) const;
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;

        return v1;
    }

    Vector2D operator/(double scalar);
    Vector2D& operator/=(double scalar);

    void normalize();
};