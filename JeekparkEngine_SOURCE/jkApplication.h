#pragma once

#include "CommonInclude.h"
#include "jkGameObject.h"

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
        void Release();

        HWND GetHwnd() { return mHwnd; }
        HDC GetHdc() { return mHdc; }
        UINT GetWidth() { return mWidth; }
        UINT GetHeight() { return mHeight; }

    private:
        void clearRenderTarget(HDC target);
        void copyRenderTarget(HDC source, HDC dest);
        void adjustWindowRect(HWND hwnd, UINT width, UINT height);
        void createBuffer(UINT width, UINT height);
        void initializeETC();

        HWND mHwnd;
        HDC mHdc;

        HDC mBackHdc;
        HBITMAP mBackBitmap;

        UINT mWidth;
        UINT mHeight;

    };


}

