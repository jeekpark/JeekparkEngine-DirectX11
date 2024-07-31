#pragma once
#include "CommonInclude.h"



namespace jk
{
    class GameObject
    {
    public:
        GameObject();
        ~GameObject();

        void Update();
        void LateUpdate();
        void Render(HDC hdc);

        void SetPosition(float x, float y)
        {
            mX = x;
            mY = y;
        }

        float GetPostionX() { return mX; }
        float GetPostionY() { return mY; }
    private:
        float mX;
        float mY;
    };

}

