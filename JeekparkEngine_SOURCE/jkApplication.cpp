#include "jkApplication.h"
#include "jkInput.h"
#include "jkTime.h"

namespace jk
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0U)
        , mHeight(0U)
        , mBackBitmap(nullptr)
        , mBackHdc(nullptr)
    {
    }

    Application::~Application()
    {
    }

    void Application::Initialize(HWND hwnd, UINT width, UINT height)
    {
        adjustWindowRect(hwnd, width, height);
        createBuffer(width, height);
        initializeETC();

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
        Input::Update();
        Time::Update();

        mPlayer.Update();
    }

    void Application::LateUpdate()
    {
    }

    void Application::Render()
    {
        clearRenderTarget(mBackHdc);

        Time::Render(mBackHdc);
        mPlayer.Render(mBackHdc);

        copyRenderTarget(mBackHdc, mHdc);
    }


    void Application::clearRenderTarget(HDC target)
    {
        Rectangle(target, -1, -1, 1921, 1081);
    }

    void Application::copyRenderTarget(HDC source, HDC dest)
    {
        BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
    }

    void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);
        RECT rect = { 0, 0, width, height };
        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        SetWindowPos(
            hwnd,
            nullptr,
            0,
            0,
            mWidth,
            mHeight,
            0U
        );
        ShowWindow(hwnd, true);
    }

    void Application::createBuffer(UINT width, UINT height)
    {
        mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
        mBackHdc = CreateCompatibleDC(mHdc);
        HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
        DeleteObject(oldBitmap);
    }

    void Application::initializeETC()
    {
        Input::Initialize();
        Time::Initialize();
    }
}