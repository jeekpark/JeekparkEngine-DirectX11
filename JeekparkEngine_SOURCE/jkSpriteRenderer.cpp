#include "jkSpriteRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"
#include "jkTexture.h"

namespace jk
{
    SpriteRenderer::SpriteRenderer()
        : Component()
        , mTexture(nullptr)
        , mScale(Vector2::One)
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
    void SpriteRenderer::Render(HDC hdc)
    {
        assert(mTexture != nullptr);
        
        Transform* tr = GetOwner()->GetComponent<Transform>();
        const Vector2& pos = tr->GetPosition();

        if (mTexture->GetTextureType()
            == graphics::Texture::eTextureType::Bmp)
        {
            TransparentBlt(
                hdc,
                pos.x, pos.y,
                mTexture->GetWidth(), mTexture->GetHeight(),
                mTexture->GetHdc(),
                0, 0,
                mTexture->GetWidth(), mTexture->GetHeight(),
                RGB(255, 0, 255)
            );
        }
        else if (mTexture->GetTextureType()
            == graphics::Texture::eTextureType::Png)
        {
            Gdiplus::Graphics graphics(hdc);
            graphics.DrawImage(
                mTexture->GetImage(),
                Gdiplus::Rect(
                    pos.x,
                    pos.y, 
                    mTexture->GetWidth() * mScale.x,
                    mTexture->GetHeight() * mScale.y
                )
            );
        }
    }

}