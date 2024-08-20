#include "jkSakuyaScript.h"

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
    SakuyaScript::SakuyaScript()
        : mState(eState::Idle)
        , mAnimator(nullptr)
        , mbLeftDirection(false)
        , mRunSpeed(600.f)
        , mbIsStay(false)
    {
    }
    SakuyaScript::~SakuyaScript()
    {
    }
    void SakuyaScript::Initialize()
    {
        mAnimator = GetOwner()->GetComponent<Animator>();
        mAnimator->PlayAnimation(L"Idle", true);
    }
    void SakuyaScript::Update()
    {
        switch (mState)
        {
        case jk::SakuyaScript::eState::Idle:
            idle();
            break;
        case jk::SakuyaScript::eState::StartRun:
            startRun();
            break;
        case jk::SakuyaScript::eState::Run:
            run();
            break;
        case jk::SakuyaScript::eState::EndRun:
            endRun();
            break;
        case jk::SakuyaScript::eState::None:
            break;
        default:
            assert(false);
            break;
        }
    }
    void SakuyaScript::LateUpdate()
    {
    }
    void SakuyaScript::Render(HDC hdc)
    {
        if (mbIsStay)
        {
            wchar_t str[50] = L"Stay";
            size_t len = wcsnlen_s(str, 50);
            TextOut(hdc, 0, 0, str, (int)len);
        }
    }
    void SakuyaScript::OnCollisionEnter(Collider* other)
    {
        
    }
    void SakuyaScript::OnCollisionStay(Collider* other)
    {
        mbIsStay = true;
    }
    void SakuyaScript::OnCollisionExit(Collider* other)
    {
        mbIsStay = false;
    }
    void SakuyaScript::AttackEffect()
    {
    }
    void SakuyaScript::idle()
    {
        if (Input::GetKeyDown(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Left))
        {
            mState = eState::StartRun;
            if (Input::GetKeyDown(eKeyCode::Right))
            {
                mbLeftDirection = false;
            }
            else
            {
                mbLeftDirection = true;
            }
            mAnimator->PlayAnimation(L"StartRun", false, mbLeftDirection);
            return;
        }
    }
    void SakuyaScript::startRun()
    {
        if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left))
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", true, mbLeftDirection);
            return;
        }
        if (mAnimator->IsComplete())
        {
            mState = eState::Run;
            mAnimator->PlayAnimation(L"Run", true, mbLeftDirection);
        }

    }
    void SakuyaScript::run()
    {
        if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left))
        {
            mState = eState::EndRun;
            mAnimator->PlayAnimation(L"EndRun", false, mbLeftDirection);
            return;
        }
        Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

        if (mbLeftDirection)
        {
            rb->AddForce(Vector2(-200.f, 0.f));
        }
        else
        {
            rb->AddForce(Vector2(200.f, 0.f));
        }
    }
    void SakuyaScript::endRun()
    {
        if (Input::GetKey(eKeyCode::Right) || Input::GetKey(eKeyCode::Left))
        {
            mState = eState::Run;
            if (Input::GetKey(eKeyCode::Right))
            {
                mbLeftDirection = false;
            }
            else
            {
                mbLeftDirection = true;
            }
            mAnimator->PlayAnimation(L"Run", true, mbLeftDirection);
        }
        if (mAnimator->IsComplete())
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", true, mbLeftDirection);
        }
    }


}