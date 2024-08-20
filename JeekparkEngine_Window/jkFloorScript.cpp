#include "jkFloorScript.h"

#include "jkRigidbody.h"
#include "jkGameObject.h"
#include "jkCollider.h"
namespace jk
{
    FloorScript::FloorScript()
    {
    }
    FloorScript::~FloorScript()
    {
    }
    void FloorScript::Initialize()
    {
    }
    void FloorScript::Update()
    {
    }
    void FloorScript::LateUpdate()
    {
    }
    void FloorScript::Render(HDC hdc)
    {
    }
    void FloorScript::OnCollisionEnter(Collider* other)
    {
        Rigidbody* rb = other->GetOwner()->GetComponent<Rigidbody>();
        rb->SetGround(true);
    }
    void FloorScript::OnCollisionStay(Collider* other)
    {
    }
    void FloorScript::OnCollisionExit(Collider* other)
    {
    }
}
