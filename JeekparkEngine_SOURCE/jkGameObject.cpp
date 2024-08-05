#include "jkGameObject.h"

#include "jkInput.h"
#include "jkTime.h"

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
        const float speed = 200.f;
        if (Input::GetKey(eKeyCode::Left))
        {
            mX -= speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::Right))
        {
            mX += speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::Up))
        {
            mY -= speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::Down))
        {
            mY += speed * Time::DeltaTime();
        }
    }

    void GameObject::LateUpdate()
    {
    }

    void GameObject::Render(HDC hdc)
    {
        HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, 100, 200));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

        Ellipse(hdc, (int)mX, (int)mY, 100 + (int)mX, 100 + (int)mY);
        SelectObject(hdc, oldBrush);
        DeleteObject(blueBrush);
    }
}