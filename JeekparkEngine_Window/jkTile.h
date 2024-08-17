#pragma once

#include "..\JeekparkEngine_SOURCE\jkGameObject.h"

namespace jk
{
    class Tile : public GameObject
    {
    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetPositionInGrid(int x, int y, Vector2 gridSize);
    };
}

