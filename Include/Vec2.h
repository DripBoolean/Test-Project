#pragma once

#include <math.h>
#include <iostream>


/**
 * @brief Vector 2 containg 2 type Ts
 * 
 * @tparam T Should probably be an int or float, anything else is a bit sus
 */
template<class T>
class Vec2
{
public:

    T x = (T)0;
    T y = (T)0;

    Vec2() {}

    Vec2(T x, T y): x(x), y(y)
    {
    }

    Vec2<T>& operator=(const Vec2<T>& other)
    {
        x = other.x;
        y = other.y;
        return *this;
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
        return *this;
    }

    Vec2& operator-=(const Vec2<T>& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(const float scalar)
    {
        x *= scalar, y *= scalar;
        return *this;
    }

    Vec2& operator/=(const float scalar)
    {
        x /= scalar, y /= scalar;
        return *this;
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

    /**
     * @brief Rotates the vector
     * 
     * @param angle Angle to rotate by (In Radians)
     */
    void rotate(T angle)
    {
        float temp_x = x * cos(angle) - y * sin(angle);
        y = x * sin(angle) + y * cos(angle);
        x = temp_x;
    }

    /**
     * @brief Normalizes the vector
     * 
     */
    void normalize() {
        (*this) /= mag();
    }

};

/**
 * @brief Returns the dot product of 2 vectors
 * 
 * @tparam T 
 * @param a Vector 1
 * @param b Vector 2
 * @return T 
 */
template <class T>
T dot(Vec2<T> a, Vec2<T> b)
{
    return (a.x * b.x) + (a.y * b.y);
}

/**
 * @brief Returns the distance between 2 points
 * 
 * @tparam T 
 * @param a Point 1
 * @param b Point 2
 * @return T Distance between the 2 points
 */
template <class T>
T distance(Vec2<T> a, Vec2<T> b) {
    return (a - b).mag();
}

/**
 * @brief Return a rotated version of a vector
 * 
 * @tparam T 
 * @param v The vector
 * @param angle Angle rotated by
 * @return Vec2<T> 
 */
template <class T>
Vec2<T> rotated(Vec2<T> v, float angle) {
    v.rotate(angle);
    return v;
}

/**
 * @brief Return a normalized version of a vector
 * 
 * @tparam T 
 * @param v The vector
 * @return Vec2<T> 
 */
template <class T>
Vec2<T> normalized(Vec2<T> v) {
    v.normalize();
    return v;
}


// template <class T>
// inline bool Vec2<T>::operator==(const Vec2<T>& a, const Vec2<T>& b)
// {
//     return a.x == b.x && a.y == b.y;
// }