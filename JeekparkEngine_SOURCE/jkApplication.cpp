#include "jkApplication.h"

#include "jkInput.h"
#include "jkTime.h"
#include "jkSceneManager.h"
#include "jkResources.h"

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

        SceneManager::Initialize();
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

        SceneManager::Update();
    }

    void Application::LateUpdate()
    {
        SceneManager::LateUpdate();
    }

    void Application::Render()
    {
        clearRenderTarget(mBackHdc);

        Time::Render(mBackHdc);
        SceneManager::Render(mBackHdc);
        
        copyRenderTarget(mBackHdc, mHdc);
    }

    void Application::Release()
    {
        SceneManager::Release();
        Resources::Release();
    }


    void Application::clearRenderTarget(HDC target)
    {
        Rectangle(target, -1, -1, 1000, 1000);
    }

    void Application::copyRenderTarget(HDC source, HDC dest)
    {
        BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
    }

    void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);
        RECT rect = { 0, 0, (LONG)width, (LONG)height };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;
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