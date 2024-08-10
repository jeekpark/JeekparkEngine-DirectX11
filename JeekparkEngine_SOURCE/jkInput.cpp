#include "jkInput.h"

#include "jkApplication.h"

extern jk::Application app;

namespace jk
{
    std::vector<Input::Key> Input::mKeys = {};
    math::Vector2 Input::mMousePostion = { 0.f, 0.f };
    int ASCII[(size_t)eKeyCode::End] =
    {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
        'Z', 'X', 'C', 'V', 'B', 'N', 'M',
        VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
        VK_LBUTTON, VK_MBUTTON, VK_RBUTTON
    };

    void Input::Initialize()
    {
        
        for (size_t i = 0; i < (size_t)eKeyCode::End; ++i)
        {
            Key key = {};
            key.bPressed = false;
            key.state = eKeyState::None;
            key.keyCode = (eKeyCode)i;

            mKeys.push_back(key);
        }
    }

    void Input::Update()
    {
        if (GetFocus())
        {
            for (size_t i = 0; i < mKeys.size(); ++i)
            {
                if (GetAsyncKeyState(ASCII[i]) & 0x8000)
                {
                    if (mKeys[i].bPressed == true)
                    {
                        mKeys[i].state = eKeyState::Pressed;
                    }
                    else
                    {
                        mKeys[i].state = eKeyState::Down;
                    }
                    mKeys[i].bPressed = true;
                }
                else
                {
                    if (mKeys[i].bPressed == true)
                    {
                        mKeys[i].state = eKeyState::Up;
                    }
                    else
                    {
                        mKeys[i].state = eKeyState::None;
                    }
                    mKeys[i].bPressed = false;
                }
            }

            POINT mousePos = {};
            GetCursorPos(&mousePos);
            ScreenToClient(app.GetHwnd(), &mousePos);
            mMousePostion.x = mousePos.x;
            mMousePostion.y = mousePos.y;
        }
        else
        {
            for (Key& key : mKeys)
            {
                if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
                {
                    key.state = eKeyState::Up;
                }
                else if (key.state == eKeyState::Up)
                {
                    key.state == eKeyState::None;
                }

                key.bPressed = false;
            }
        }
        
    }

}
