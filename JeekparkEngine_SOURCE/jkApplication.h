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
    private:
        void clearRenderTarget(HDC targ et);
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
        
        GameObject mPlayer;
    };


}

