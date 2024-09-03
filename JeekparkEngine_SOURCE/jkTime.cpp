#include "jkTime.h"


namespace jk
{
    LARGE_INTEGER Time::sCpuFrequency = {};
    LARGE_INTEGER Time::sPrevCpuFrequency = {};
    LARGE_INTEGER Time::sCurrentCpuFrequency = {};
    float Time::sDeltaTime = 0.f;

    void Time::Initialize()
    {
        // CPU 고유 진동수
        QueryPerformanceFrequency(&sCpuFrequency);

        // 프로그램이 시작 했을 때 현재 진동수
        QueryPerformanceCounter(&sPrevCpuFrequency);
    }
    void Time::Update()
    {
        QueryPerformanceCounter(&sCurrentCpuFrequency);

        float differenceFrequency
            = static_cast<float>(sCurrentCpuFrequency.QuadPart - sPrevCpuFrequency.QuadPart);

        sDeltaTime = differenceFrequency / static_cast<float>(sCpuFrequency.QuadPart);
        sPrevCpuFrequency.QuadPart = sCurrentCpuFrequency.QuadPart;
    }

    void Time::Render()
    {
    }
}
