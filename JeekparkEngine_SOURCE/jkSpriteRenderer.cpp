#include "jkSpriteRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"
#include "jkTexture.h"
#include "jkRenderer.h"
#include "jkResources.h"

namespace jk
{
    SpriteRenderer::SpriteRenderer()
        : Component(enums::eComponentType::SpriteRenderer)
        , mSprite(nullptr)
        , mMaterial(nullptr)
        , mMesh(nullptr)
    {
    }
    SpriteRenderer::~SpriteRenderer()
    {
    }
    void SpriteRenderer::Initialize()
    {
        mMesh = Resources::Find<Mesh>(L"RectMesh");
        mMaterial = Resources::Find<Material>(L"Sprite-Default-Material");
    }
    void SpriteRenderer::Update()
    {
    }
    void SpriteRenderer::LateUpdate()
    {
    }
    void SpriteRenderer::Render()
    {
        if (mMesh)
            mMesh->Bind();

        if (mMaterial)
            mMaterial->BindShader();

        if (mSprite)
            mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Albedo);

        if (mMesh)
            graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
    }

}