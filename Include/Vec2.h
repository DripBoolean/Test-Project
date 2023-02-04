#include <math.h>
#include <iostream>

template<class T>
class Vec2
{
public:

    T x = (T)0;
    T y = (T)0;
    Vec2(T x, T y): x(x), y(y)
    {
    }

    Vec2<T>& operator=(const Vec2<T>& other)
    {
        x = other.x;
        y = other.y;
    }

    Vec2 operator+(const Vec2<T>& other)
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2<T>& other)
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(const float scalar)
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(const float scalar)
    {
        return Vec2(x / scalar, y / scalar);
    }

    Vec2& operator+=(const Vec2<T>& other)
    {
        x += other.x;
        y += other.y;
        return this;
    }

    Vec2& operator-=(const Vec2<T>& other)
    {
        x -= other.x;
        y -= other.y;
        return this;
    }

    Vec2& operator*=(const float scalar)
    {
        x *= scalar, y *= scalar;
        return this;
    }

    Vec2& operator/=(const float scalar)
    {
        x /= scalar, y /= scalar;
        return this;
    }

    T mag2()
    {
        return (x * x) + (y * y);
    }

    T mag()
    {
        return sqrt(mag2());
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& f)
    {
        os << "<" << f.x << ", " << f.y << ">";
        return os;
    }

};

template <class T>
T dot(Vec2<T> a, Vec2<T> b)
{
    return (a.x * b.x) + (a.y * b.y);
}

// template <class T>
// inline bool Vec2<T>::operator==(const Vec2<T>& a, const Vec2<T>& b)
// {
//     return a.x == b.x && a.y == b.y;
// }