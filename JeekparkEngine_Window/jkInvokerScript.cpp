#include "jkInvokerScript.h"

#include "jkGameObject.h"
#include "jkComponent.h"
#include "jkAnimator.h"
#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
#include "jkCollider.h"
#include "jkRigidbody.h"
namespace jk
{
    InvokerScript::InvokerScript()
        : mState(eState::Idle)
        , mAnimator(nullptr)
    {
    }
    InvokerScript::~InvokerScript()
    {
    }
    void InvokerScript::Initialize()
    {
        mAnimator = GetOwner()->GetComponent<Animator>();
        mAnimator->PlayAnimation(L"Idle", true);
    }
    void InvokerScript::Update()
    {
        switch (mState)
        {
        case jk::InvokerScript::eState::Idle:
            idle();
            break;
        case jk::InvokerScript::eState::StartRun:
            startRun();
            break;
        case jk::InvokerScript::eState::Run:
            run();
            break;
        case jk::InvokerScript::eState::EndRun:
            endRun();
            break;
        case jk::InvokerScript::eState::None:
            break;
        default:
            assert(false);
            break;
        }
    }
    void InvokerScript::LateUpdate()
    {
    }
    void InvokerScript::Render(HDC hdc)
    {

    }
    void InvokerScript::OnCollisionEnter(Collider* other)
    {
        
    }
    void InvokerScript::OnCollisionStay(Collider* other)
    {

    }
    void InvokerScript::OnCollisionExit(Collider* other)
    {

    }
    void InvokerScript::AttackEffect()
    {
    }
    void InvokerScript::idle()
    {

    }
    void InvokerScript::startRun()
    {


    }
    void InvokerScript::run()
    {

    }
    void InvokerScript::endRun()
    {

    }


}