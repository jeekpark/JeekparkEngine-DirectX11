#pragma once

#include "..\JeekparkEngine_SOURCE\jkScene.h"

namespace jk
{
    class ToolScene : public Scene
    {
    public:
        ToolScene();
        ~ToolScene();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;
    private:
        Vector2 mGridSize;
    };

}
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
