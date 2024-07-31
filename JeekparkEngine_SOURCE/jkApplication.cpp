#include "jkApplication.h"
#include "jkInput.h"

namespace jk
{
    jk::Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mSpeed(0.f)
    {
    }

    jk::Application::~Application()
    {
    }

    void Application::Initialize(HWND hwnd)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);

        mPlayer.SetPosition(0.f, 0.f);
        Input::Initialize();
    }

    void Application::Run()
    {
        Update();
        LateUpdate();
        Render();
    }

    void Application::Update()
    {
        mPlayer.Update();
        Input::Update();
    }

    void Application::LateUpdate()
    {
    }

    void Application::Render()
    {
        mPlayer.Render(mHdc);
    }

}