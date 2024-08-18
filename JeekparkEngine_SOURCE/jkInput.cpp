#include "jkInput.h"

#include "jkApplication.h"

extern jk::Application app;

namespace jk
{
    std::vector<Input::Key> Input::Keys = {};
    math::Vector2 Input::mMousePosition = { 0.f, 0.f };
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

            Keys.push_back(key);
        }
    }

	void Input::Update()
	{
		updateKeys();
	}
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(app.GetHwnd(), &mousePos);

		UINT width = app.GetWidth();
		UINT height = app.GetHeight();

		mMousePosition.x = -1.0f;
		mMousePosition.y = -1.0f;

		if (0 < mousePos.x && mousePos.x < width)
			mMousePosition.x = mousePos.x;

		if (0 < mousePos.y && mousePos.y < height)
			mMousePosition.y = mousePos.y;
	}
	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}

}
