#pragma once

#include "..\JeekparkEngine_SOURCE\jkScene.h"
#include "jkTile.h"
namespace jk
{
    class ToolScene : public Scene
    {
    public:
        static Vector2 SelectedIndex;
        ToolScene();
        ~ToolScene();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

        void Save();
        void Load();
    private:
        void clearTiles();
    private:
        Vector2 mGridSize;
        std::vector<Tile*> mTiles;
    };

}
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
