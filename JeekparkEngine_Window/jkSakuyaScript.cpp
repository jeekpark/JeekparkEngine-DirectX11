#include "jkSakuyaScript.h"

#include "jkGameObject.h"
#include "jkComponent.h"
#include "jkAnimator.h"
#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
namespace jk
{
    SakuyaScript::SakuyaScript()
        : mState(eState::Idle)
        , mAnimator(nullptr)
        , mDirection(enums::eDirection::Right)
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
            break;
        case jk::SakuyaScript::eState::RunJump:
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
    void SakuyaScript::AttackEffect()
    {
    }
    void SakuyaScript::idle()
    {
        if (Input::GetKey(eKeyCode::Right))
        {
            mState = eState::StartRun;
            mAnimator->PlayAnimation(L"StartRun", false);
        }
    }
    void SakuyaScript::startRun()
    {

        if (Input::GetKey(eKeyCode::Right) == false)
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", true);
            return;
        }

        if (mAnimator->IsComplete())
        {
            mState = eState::Run;
            mAnimator->PlayAnimation(L"Run", true);
        }

    }
    void SakuyaScript::run()
    {
        if (Input::GetKey(eKeyCode::Right) == false)
        {
            mState = eState::EndRun;
            mAnimator->PlayAnimation(L"EndRun", false);
            return;
        }
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        pos += Vector2::Right * 500.f * Time::DeltaTime();
        tr->SetPosition(pos);
    }
    void SakuyaScript::endRun()
    {
        if (mAnimator->IsComplete())
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", true);
        }
    }

}