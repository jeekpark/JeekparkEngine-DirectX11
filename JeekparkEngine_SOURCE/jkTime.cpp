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

    void Time::Render(HDC hdc)
    {
        static float time = 0.f;

        time += sDeltaTime;
        float fps = 1.f / sDeltaTime;

        wchar_t str[50] = L"";
        swprintf_s(str, 50, L"FPS: %f", fps);
        size_t len = wcsnlen_s(str, 50);

        
        
        TextOut(hdc, 0, 20, str, (int)len);
    }
}
