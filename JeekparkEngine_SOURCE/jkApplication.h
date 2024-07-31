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

        void Initialize(HWND hwnd);
        void Run();

        void Update();
        void LateUpdate();
        void Render();
    private:
        HWND mHwnd;
        HDC mHdc;

        float mSpeed;
        
        GameObject mPlayer;
    };


}

