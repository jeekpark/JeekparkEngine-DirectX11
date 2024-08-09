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
    void SpriteRenderer::Render(HDC hdc)
    {
        assert(mTexture != nullptr);
        
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        pos = renderer::mainCamera->CalculatePosition(pos);
        if (mTexture->GetTextureType()
            == graphics::Texture::eTextureType::Bmp)
        {
            
            TransparentBlt(
                hdc,
                pos.x, pos.y,
                mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y,
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
                    mTexture->GetWidth() * mSize.x,
                    mTexture->GetHeight() * mSize.y
                )
            );
        }
    }

}