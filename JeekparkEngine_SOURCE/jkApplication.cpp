#include "jkApplication.h"

#include "jkInput.h"
#include "jkTime.h"
#include "jkSceneManager.h"
#include "jkResources.h"
#include "jkCollisionManager.h"

namespace jk
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0U)
        , mHeight(0U)
        , mClientWidth(0U)
        , mClientHeight(0U)
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

        CollisionManager::Initialize();
        SceneManager::Initialize();
    }

    void Application::Run()
    {
        Update();
        LateUpdate();
        Render();

        Destroy();
    }

    void Application::Update()
    {
        Input::Update();
        Time::Update();
        CollisionManager::Update();
        SceneManager::Update();
    }

    void Application::LateUpdate()
    {
        CollisionManager::LateUpdate();
        SceneManager::LateUpdate();
    }

    void Application::Render()
    {
        clearRenderTarget(mBackHdc);

        Time::Render(mBackHdc);
        CollisionManager::Render(mBackHdc);
        SceneManager::Render(mBackHdc);
        
        copyRenderTarget(mBackHdc, mHdc);
    }
    void Application::Destroy()
    {
        SceneManager::Destroy();
    }
    void Application::Release()
    {
        SceneManager::Release();
        Resources::Release();
    }


    void Application::clearRenderTarget(HDC target)
    {
        HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(127, 127, 127));
        HBRUSH oldBrush = (HBRUSH)SelectObject(target, grayBrush);
        Rectangle(target, -1, -1, mClientWidth + 1, mClientHeight + 1);

        SelectObject(target, oldBrush);
        DeleteObject(grayBrush);
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
            1500,
            0,
            mWidth,
            mHeight,
            0U
        );
        ShowWindow(hwnd, true);

        RECT clientRect;
        GetClientRect(mHwnd, &clientRect);
        mClientWidth = clientRect.right - clientRect.left;
        mClientHeight = clientRect.bottom - clientRect.top;
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