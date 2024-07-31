#include "jkGameObject.h"

namespace jk
{
    GameObject::GameObject()
        : mX(0.f)
        , mY(0.f)
    {
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Update()
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            mX -= 0.01f;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            mX += 0.01f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            mY -= 0.01f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            mY += 0.01f;
        }
    }

    void GameObject::LateUpdate()
    {
    }

    void GameObject::Render(HDC hdc)
    {
        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 100, 200));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

        Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
        SelectObject(hdc, oldBrush);
        DeleteObject(blueBrush);
    }
}