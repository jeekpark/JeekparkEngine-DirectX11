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
        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 200));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

        HPEN redPen = CreatePen(PS_SOLID, 3,
            RGB(rand() % 200, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
        
        Transform* tr = GetOwner()->GetComponent<Transform>();

        Rectangle(hdc,
            tr->GetX(), tr->GetY(),
            tr->GetX() + 100, tr->GetY() + 100);

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(blueBrush);
        DeleteObject(redPen);
    }
}