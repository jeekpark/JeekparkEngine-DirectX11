#pragma once

#include "jkComponent.h"
#include "jkTexture.h"

namespace jk
{
    class SpriteRenderer : public Component
    {
    public:
        SpriteRenderer();
        ~SpriteRenderer();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render(HDC hdc)  override;

        void SetTexture(graphics::Texture* texture) { mTexture = texture; }
        void SetSize(math::Vector2 size) { mScale = size; }
    private:
        graphics::Texture* mTexture;
        math::Vector2 mScale;
    };
}

