#include "jkSakuyaScript.h"

#include "jkGameObject.h"
#include "jkComponent.h"
#include "jkAnimator.h"
#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
#include "jkCollider.h"
namespace jk
{
    SakuyaScript::SakuyaScript()
        : mState(eState::Idle)
        , mAnimator(nullptr)
        , mbLeftDirection(false)
        , mRunSpeed(600.f)
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
        case jk::SakuyaScript::eState::SitDown:
            break;
        case jk::SakuyaScript::eState::StopJump:
            stopJump();
            break;
        case jk::SakuyaScript::eState::RunJump:
            runJump();
            break;
        case jk::SakuyaScript::eState::Float:
            break;
        case jk::SakuyaScript::eState::Attack:
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
    }
    void SakuyaScript::OnCollisionEnter(Collider* other)
    {
        
    }
    void SakuyaScript::OnCollisionStay(Collider* other)
    {
        
    }
    void SakuyaScript::OnCollisionExit(Collider* other)
    {
        
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
        if (Input::GetKeyDown(eKeyCode::Up))
        {
            mState = eState::StopJump;
            mAnimator->PlayAnimation(L"StopJump", false, mbLeftDirection);
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
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (mbLeftDirection)
        {
            pos += Vector2::Left * (mRunSpeed / 10) *Time::DeltaTime();
        }
        else
        {
            pos += Vector2::Right * (mRunSpeed / 10) * Time::DeltaTime();
        }
        tr->SetPosition(pos);
    }
    void SakuyaScript::run()
    {
        if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left))
        {
            mState = eState::EndRun;
            mAnimator->PlayAnimation(L"EndRun", false, mbLeftDirection);
            return;
        }
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (mbLeftDirection)
        {
            pos += Vector2::Left * mRunSpeed * Time::DeltaTime();
        }
        else
        {
            pos += Vector2::Right * mRunSpeed * Time::DeltaTime();
        }
        tr->SetPosition(pos);
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

    void SakuyaScript::stopJump()
    {
        if (mAnimator->IsComplete())
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", true, mbLeftDirection);
        }
    }

    void SakuyaScript::runJump()
    {
    }

}