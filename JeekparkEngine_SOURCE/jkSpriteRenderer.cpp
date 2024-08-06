#include "jkSpriteRenderer.h"

#include "jkGameObject.h"
#include "jkTransform.h"

namespace jk
{
    SpriteRenderer::SpriteRenderer()
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
        /*Transform* tr = GetOwner()->GetComponent<Transform>();

        const Vector2& pos = tr->GetPosition();

        Gdiplus::Graphics graphics(hdc);
        graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));*/

    }

}