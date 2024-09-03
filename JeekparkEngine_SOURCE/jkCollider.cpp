#include "jkCollider.h"

#include "jkScript.h"
#include "jkGameObject.h"

namespace jk
{
    UINT32 Collider::sCollistionID = 1;

    Collider::Collider(enums::eColliderType type)
        : Component(enums::eComponentType::Collider)
        , mID(sCollistionID++)
        , mSize(Vector2::One)
        , mColliderType(type)
    {
    }
    Collider::~Collider()
    {
    }
    void Collider::Initialize()
    {
    }
    void Collider::Update()
    {
    }
    void Collider::LateUpdate()
    {
    }
    void Collider::Render()
    {
    }
    void Collider::OnCollisionEnter(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        if (script)
        {
            script->OnCollisionEnter(other);
        }

    }
    void Collider::OnCollisionStay(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        if (script)
        {
            script->OnCollisionStay(other);
        }
    }
    void Collider::OnCollisionExit(Collider* other)
    {
        Script* script = GetOwner()->GetComponent<Script>();
        if (script)
        {
            script->OnCollisionExit(other);
        }
    }
}