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

        HWND GetHwnd() const { return mHwnd; }
        HDC GetHdc() const { return mHdc; }
        UINT GetWidth() const { return mWidth; }
        UINT GetHeight() const { return mHeight; }
        UINT GetClientWidth() const { return mClientWidth; }
        UINT GetClientHeight() const { return mClientHeight; }

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

