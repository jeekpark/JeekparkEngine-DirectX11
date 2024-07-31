#include "jkApplication.h"

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
    }

    void Application::LateUpdate()
    {
    }

    void Application::Render()
    {
        mPlayer.Render(mHdc);
    }

}