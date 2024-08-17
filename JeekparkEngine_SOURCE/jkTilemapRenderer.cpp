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
        , mTileSize(Vector2::One)
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
    void TilemapRenderer::Render(HDC hdc)
    {
        assert(mTexture != nullptr);

        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        Vector2 scl = tr->GetScale();
        float rot = tr->GetRotation();
        if (renderer::mainCamera)
        {
            pos = renderer::mainCamera->WorldToScreenPoint(pos);
        }
        if (mTexture->GetTextureType()
            == graphics::Texture::eTextureType::Bmp)
        {
            if (mTexture->IsAlpha())
            {
                BLENDFUNCTION func = {};
                func.BlendOp = AC_SRC_OVER;
                func.BlendFlags = 0;
                func.AlphaFormat = AC_SRC_ALPHA;
                func.SourceConstantAlpha = 255;

                AlphaBlend(hdc,
                    pos.x,
                    pos.y,
                    mTileSize.x * scl.x,
                    mTileSize.y * scl.y,
                    mTexture->GetHdc(),
                    mIndex.x * mTileSize.x,
                    mIndex.y * mTileSize.y,
                    mTileSize.x,
                    mTileSize.y,
                    func
                );
            }
            else
            {
                TransparentBlt(hdc,
                    pos.x,
                    pos.y,
                    mTileSize.x * scl.x,
                    mTileSize.y * scl.y,
                    mTexture->GetHdc(),
                    mIndex.x * mTileSize.x,
                    mIndex.y * mTileSize.y,
                    mTileSize.x,
                    mTileSize.y,
                    RGB(255, 0, 255)
                );
            }
        }
        else if (mTexture->GetTextureType()
            == graphics::Texture::eTextureType::Png)
        {
            Gdiplus::ImageAttributes imgAtt = {};
            imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

            Gdiplus::Graphics graphics(hdc);

            graphics.TranslateTransform(pos.x, pos.y);
            graphics.RotateTransform(rot);
            graphics.TranslateTransform(-pos.x, -pos.y);

            graphics.DrawImage(
                mTexture->GetImage(),
                Gdiplus::Rect(
                    pos.x,
                    pos.y,
                    mTexture->GetWidth() * scl.x,
                    mTexture->GetHeight() * scl.y
                ),
                0,
                0,
                mTexture->GetWidth(),
                mTexture->GetHeight(),
                Gdiplus::UnitPixel,
                nullptr//&imgAtt
            );


        }
    }

}