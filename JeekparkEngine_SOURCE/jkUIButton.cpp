#include "jkUIButton.h"
#include "jkInput.h"

namespace jk
{
    UIButton::UIButton()
        : UIBase(eUIType::Button)
    {
    }
    UIButton::~UIButton()
    {
    }
    void UIButton::OnInit()
    {
        SetPos({200.f, 200.f});
        SetSize({ 200.f, 200.f });
        mOnClick = std::bind(&UIButton::ButtonClick, this);
    }
    void UIButton::OnActive()
    {
    }
    void UIButton::OnInActive()
    {
    }
    void UIButton::OnUpdate()
    {
        Vector2 mousePos = Input::GetMousePostion();
        if (mousePos.x > mPosition.x && mousePos.x < mPosition.x + mSize.x &&
            mousePos.y > mPosition.y && mousePos.y < mPosition.y + mSize.y)
        {
            mbMouseOn = true;
        }
        else
        {
            mbMouseOn = false;
        }

        if (Input::GetKeyDown(eKeyCode::LButton) && mbMouseOn)
        {
            mOnClick();
        }
    }
    void UIButton::OnLateUpdate()
    {
    }
    void UIButton::OnRender(HDC hdc)
    {
        if (mbMouseOn)
        {
            Rectangle(hdc, mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y);
        }
        else
        {
            Rectangle(hdc, mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y + 100);

        }
        
    }
    void UIButton::OnClear()
    {
    }
    void UIButton::ButtonClick()
    {
        int a = 0;
    }
}