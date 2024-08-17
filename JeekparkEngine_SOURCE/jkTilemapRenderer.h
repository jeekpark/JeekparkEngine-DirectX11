#pragma once

#include "jkComponent.h"
#include "jkTexture.h"

namespace jk
{
    class TilemapRenderer : public Component
    {
    public:
        TilemapRenderer();
        ~TilemapRenderer();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render(HDC hdc)  override;

        void SetTexture(graphics::Texture* texture) { mTexture = texture; }
        void SetIndex(Vector2 index) { mIndex = index; }
        void SetTileSize(Vector2 tileSize) { mTileSize = tileSize; }

    private:
        graphics::Texture* mTexture;
        Vector2 mIndex;
        Vector2 mTileSize;
    };
}

