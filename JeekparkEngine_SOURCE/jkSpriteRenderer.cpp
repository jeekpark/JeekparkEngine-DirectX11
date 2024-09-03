#include "jkSpriteRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"
#include "jkTexture.h"
#include "jkRenderer.h"


namespace jk
{
    SpriteRenderer::SpriteRenderer()
        : Component(enums::eComponentType::SpriteRenderer)
        , mTexture(nullptr)
        , mSize(Vector2::One)
    {
    }
    SpriteRenderer::~SpriteRenderer()
    {
    }
    void SpriteRenderer::Initialize()
    {
    }
    void SpriteRenderer::Update()
    {
    }
    void SpriteRenderer::LateUpdate()
    {
    }
    void SpriteRenderer::Render()
    {
        assert(mTexture != nullptr);
    }

}