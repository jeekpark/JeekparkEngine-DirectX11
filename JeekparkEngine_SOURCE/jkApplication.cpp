#include "jkApplication.h"
#include "jkInput.h"
#include "jkTime.h"

namespace jk
{
    jk::Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0U)
        , mHeight(0U)
        , mBackBitmap(nullptr)
        , mBackHdc(nullptr)
    {
    }

    jk::Application::~Application()
    {
    }

    void Application::Initialize(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);
        
        RECT rect = { 0, 0, width, height };
        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        SetWindowPos(
            mHwnd,
            nullptr,
            100,
            100,
            mWidth,
            mHeight,
            0U
        );

        ShowWindow(mHwnd, true);

        mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

        mBackHdc = CreateCompatibleDC(mHdc);

        HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
        DeleteObject(oldBitmap);


        mPlayer.SetPosition(0.f, 0.f);
        Input::Initialize();
        Time::Initialize();
    }

    void Application::Run()
    {
        Update();
        LateUpdate();
        Render();
    }

    void Application::Update()
    {
        Input::Update();
        Time::Update();

        mPlayer.Update();
        
    }

    void Application::LateUpdate()
    {
    }

    void Application::Render()
    {
        Rectangle(mBackHdc, 0, 0, 1920, 1080);
        Time::Render(mBackHdc);
        mPlayer.Render(mBackHdc);

        BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
    }

}