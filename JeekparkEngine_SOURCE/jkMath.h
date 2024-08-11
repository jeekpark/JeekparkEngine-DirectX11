#pragma once

#include <cmath>


namespace jk::math
{
    constexpr auto M_PI = 3.14159265358979323846;
    struct Vector2
    {
        static float Dot(Vector2& v1, Vector2& v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        static float Cross(Vector2& v1, Vector2& v2)
        {
            return  v1.x * v2.y - v1.y * v2.x;
        }

        static Vector2 Rotate(Vector2& vector, float degree)
        {
            float radian = (degree / 180.f) * M_PI;
            vector.normalize();
            float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
            float y = sinf(radian) * vector.x - cosf(radian) * vector.y;
            return { x, y };
        }
        

        static Vector2 One;
        static Vector2 Zero;
        static Vector2 Left;
        static Vector2 Right;
        static Vector2 Up;
        static Vector2 Down;

        float x;
        float y;
        Vector2()
            : x(0.f)
            , y(0.f)
        {

        }

        Vector2(float _x, float _y)
            : x(_x)
            , y(_y)
        {

        }

        Vector2 operator+(Vector2 other)
        {
            return Vector2(x + other.x, y + other.y);
        }
        void operator+=(Vector2 other)
        {
            x += other.x;
            y += other.y;
        }
        Vector2 operator-(Vector2 other)
        {
            return Vector2(x - other.x, y - other.y);
        }
        Vector2 operator/(float value)
        {
            return Vector2(x / value, y / value);
        }
        Vector2 operator*(float value)
        {
            return Vector2(x * value, y * value);
        }
        Vector2 operator*(Vector2 v)
        {
            return Vector2(x * v.x, y * v.y);
        }

        void clear()
        {
            x = 0.f;
            y = 0.f;
        }

        float length()
        {
            return sqrtf(x * x + y * y);
        }

        Vector2 normalize()
        {
            float len = length();
            x /= len;
            y /= len;
            return *this;
        }
    };

    
}

