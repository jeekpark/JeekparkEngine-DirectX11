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
        void Render()  override;

        void SetTexture(graphics::Texture* texture) { mTexture = texture; }
        void SetIndex(Vector2 index) { mIndex = index; }
        void SetSourceTileSize(Vector2 tileSize) { mSourceTileSize = tileSize; }
        Vector2 GetIndex() const { return mIndex; }
    private:
        graphics::Texture* mTexture;
        Vector2 mIndex;
        Vector2 mSourceTileSize;
    };
}

