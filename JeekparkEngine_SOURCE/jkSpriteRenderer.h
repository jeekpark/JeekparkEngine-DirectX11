#pragma once

#include "jkComponent.h"
#include "jkTexture.h"
#include "jkMaterial.h"
#include "jkMesh.h"

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
        void Render()  override;

        void SetSprite(graphics::Texture* sprite) { mSprite = sprite; }
        void SetMaterial(Material* material) { mMaterial = material; }
    private:
        graphics::Texture* mSprite;
        Material* mMaterial;
        Mesh* mMesh;
    };
}

