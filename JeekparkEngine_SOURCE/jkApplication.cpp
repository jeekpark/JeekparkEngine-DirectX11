#include "jkApplication.h"

#include "jkInput.h"
#include "jkTime.h"
#include "jkSceneManager.h"
#include "jkResources.h"
#include "jkCollisionManager.h"
#include "jkUIManager.h"
#include "jkFmod.h"
#include "jkRenderer.h"

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
        , mbLoaded(false)
        , mGraphicDevice(nullptr)
    {
    }

    Application::~Application()
    {
    }

    void Application::Initialize(HWND hwnd, UINT width, UINT height)
    {
        AdjustWindowRect(hwnd, width, height);
        InitializeEtc();

        mGraphicDevice = std::make_unique<graphics::GraphicDevice_DX11>();
        //renderer::Initialize();
        mGraphicDevice->Initialize();

        Fmod::Initialize();
        CollisionManager::Initialize();
        UIManager::Initialize();
        SceneManager::Initialize();
    }
    void Application::AdjustWindowRect(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);

        RECT rect = { 0, 0, (LONG)width, (LONG)height };
        ::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;

        SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
        ShowWindow(hwnd, true);

        RECT clientRect;
        GetClientRect(mHwnd, &clientRect);
        mClientWidth = clientRect.right - clientRect.left;
        mClientHeight = clientRect.bottom - clientRect.top;
    }

    void Application::InitializeEtc()
    {
        Input::Initialize();
        Time::Initialize();
    }
    void Application::Run()
    {
        if (mbLoaded == false)
        {
            mbLoaded = true;
        }
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
        UIManager::Update();
        SceneManager::Update();
    }

    void Application::LateUpdate()
    {
        CollisionManager::LateUpdate();
        UIManager::LateUpdate();
        SceneManager::LateUpdate();
    }

    void Application::Render()
    {
        graphics::GetDevice()->ClearRenderTargetView();
        graphics::GetDevice()->ClearDepthStencilView();
        graphics::GetDevice()->BindViewPort();
        graphics::GetDevice()->BindDefaultRenderTarget();

        Time::Render();
        CollisionManager::Render();
        UIManager::Render();
        SceneManager::Render();

        graphics::GetDevice()->Present();
    }
    void Application::Destroy()
    {
        SceneManager::Destroy();
    }
    void Application::Release()
    {
        SceneManager::Release();
        UIManager::Release();
        Resources::Release();

        renderer::Release();
    }
}