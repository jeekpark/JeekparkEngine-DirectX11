#include "jkTime.h"


namespace jk
{
    LARGE_INTEGER Time::sCpuFrequency = {};
    LARGE_INTEGER Time::sPrevCpuFrequency = {};
    LARGE_INTEGER Time::sCurrentCpuFrequency = {};
    float Time::sDeltaTime = 0.f;

    void Time::Initialize()
    {
        // CPU ���� ������
        QueryPerformanceFrequency(&sCpuFrequency);

        // ���α׷��� ���� ���� �� ���� ������
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
