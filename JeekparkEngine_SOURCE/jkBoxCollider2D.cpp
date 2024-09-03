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
    void BoxCollider2D::Render()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 ownerPos = tr->GetPosition();
    }
}