#pragma once

#include "jkGameObject.h"
#include "jkGraphicDevice_DX11.h"
namespace jk
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Initialize(HWND hwnd, UINT width, UINT height);
        void Run();

        void Update();
        void LateUpdate();
        void Render();
        void Destroy();
        void Release();

        HWND GetHwnd() { return mHwnd; }
        HDC GetHdc() { return mHdc; }
        UINT GetWidth() { return mWidth; }
        UINT GetHeight() { return mHeight; }
        UINT GetClientWidth() { return mClientWidth; }
        UINT GetClientHeight() { return mClientHeight; }

    private:
        void clearRenderTarget(HDC target);
        void copyRenderTarget(HDC source, HDC dest);
        void adjustWindowRect(HWND hwnd, UINT width, UINT height);
        void createBuffer(UINT width, UINT height);
        void initializeETC();

        std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;

        HWND mHwnd;
        HDC mHdc;

        HDC mBackHdc;
        HBITMAP mBackBitmap;

        UINT mWidth;
        UINT mHeight;
        UINT mClientWidth;
        UINT mClientHeight;
    };


}

