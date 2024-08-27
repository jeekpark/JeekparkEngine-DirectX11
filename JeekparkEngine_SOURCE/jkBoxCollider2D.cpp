#include "jkBoxCollider2D.h"

#include "jkTransform.h"
#include "jkGameObject.h"
#include "jkRenderer.h"
namespace jk
{
    BoxCollider2D::BoxCollider2D()
        : Collider(enums::eColliderType::Box2D)
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
            ownerPos = renderer::mainCamera->WorldToScreenPoint(ownerPos);
        }
        Vector2 offset = GetOffset();

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

        HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        ::Rectangle(hdc,
            ownerPos.x + offset.x,
            ownerPos.y + offset.y,
            ownerPos.x + offset.x + GetSize().x,
            ownerPos.y + offset.y + GetSize().y
        );

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(greenPen);
    }
}