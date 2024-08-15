#include "jkBoxCollider2D.h"

#include "jkTransform.h"
#include "jkGameObject.h"
#include "jkRenderer.h"
namespace jk
{
    BoxCollider2D::BoxCollider2D()
        : Collider()
    {
    }
    BoxCollider2D::~BoxCollider2D()
    {
    }
    void BoxCollider2D::Initialize()
    {
    }
    void BoxCollider2D::Update()
    {
    }
    void BoxCollider2D::LateUpdate()
    {
    }
    void BoxCollider2D::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 ownerPos = tr->GetPosition();
        if (renderer::mainCamera)
        {
            ownerPos = renderer::mainCamera->CalculatePosition(ownerPos);
        }
        Vector2 ownerScl = tr->GetScale();
        Vector2 offset = GetOffset();

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

        HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        Rectangle(hdc,
            ownerPos.x + GetOffset().x,
            ownerPos.y + GetOffset().y,
            ownerPos.x + GetOffset().x + mSize.x,
            ownerPos.y + GetOffset().y + mSize.y
        );

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(greenPen);
    }
}