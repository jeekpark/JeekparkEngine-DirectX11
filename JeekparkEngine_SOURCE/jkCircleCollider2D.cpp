#include "jkCircleCollider2D.h"

#include "jkTransform.h"
#include "jkGameObject.h"
#include "jkRenderer.h"
#include "jkCamera.h"

namespace jk
{
    CircleCollider2D::CircleCollider2D()
        : Collider(enums::eColliderType::Circle2D)
        , mRadius(0.0f)
    {
    }
    CircleCollider2D::~CircleCollider2D()
    {
    }
    void CircleCollider2D::Initialize()
    {
    }
    void CircleCollider2D::Update()
    {
    }
    void CircleCollider2D::LateUpdate()
    {
    }
    void CircleCollider2D::Render()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
    }
}