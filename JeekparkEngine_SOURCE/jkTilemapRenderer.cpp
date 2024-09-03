#include "jkTilemapRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"
#include "jkTexture.h"
#include "jkRenderer.h"


namespace jk
{
    TilemapRenderer::TilemapRenderer()
        : Component(enums::eComponentType::SpriteRenderer)
        , mTexture(nullptr)
        , mIndex(Vector2::Zero)
        , mSourceTileSize(Vector2::One)
    {
    }
    TilemapRenderer::~TilemapRenderer()
    {
    }
    void TilemapRenderer::Initialize()
    {
    }
    void TilemapRenderer::Update()
    {
    }
    void TilemapRenderer::LateUpdate()
    {
    }
    void TilemapRenderer::Render()
    {
        assert(mTexture != nullptr);
    }

}