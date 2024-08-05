#include "jkSpriteRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"

namespace jk
{
    SpriteRenderer::SpriteRenderer()
        : mImage(nullptr)
        , mWidth(0U)
        , mHeight(0U)
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
        Transform* tr = GetOwner()->GetComponent<Transform>();

        const Vector2& pos = tr->GetPosition();

        Gdiplus::Graphics graphics(hdc);
        graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

    }
    void SpriteRenderer::ImageLoad(const std::wstring& path)
    {
        mImage = Gdiplus::Image::FromFile(path.c_str());
        mWidth = mImage->GetWidth();
        mHeight = mImage->GetHeight();
    }
}