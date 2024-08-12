#pragma once

#include "CommonInclude.h"

namespace jk
{
    class Time
    {
    public:
        static void Initialize();
        static void Update();
        static void Render(HDC hdc);
        __forceinline static float DeltaTime() { return sDeltaTime; }
    private:
        static LARGE_INTEGER sCpuFrequency;
        static LARGE_INTEGER sPrevCpuFrequency;
        static LARGE_INTEGER sCurrentCpuFrequency;
        static float sDeltaTime;
    };

}


