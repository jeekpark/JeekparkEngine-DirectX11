#include "jkPlayerScript.h"

#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
#include "jkGameObject.h"
#include "jkAnimator.h"
#include "jkObject.h"
#include "jkResources.h"
namespace jk
{

    PlayerScript::PlayerScript()
        : mState(PlayerScript::eState::Idle)
        , mAnimator(nullptr)
    {
    }

    PlayerScript::~PlayerScript()
    {
    }

    void PlayerScript::Initialize()
    {
        mAnimator = GetOwner()->GetComponent<Animator>();
    }

    void PlayerScript::Update()
    {
        switch (mState)
        {
        case jk::PlayerScript::eState::Idle:
            idle();
            break;
        case jk::PlayerScript::eState::Walk:
            move();
            break;
        case jk::PlayerScript::eState::Sleep:
            break;
        case jk::PlayerScript::eState::GiveWater:
            giveWater();
            break;
        case jk::PlayerScript::eState::Attack:
            break;
        default:
            break;
        }
        
    }

    void PlayerScript::LateUpdate()
    {
    }

    void PlayerScript::Render(HDC hdc)
    {
    }

    void PlayerScript::AttackEffect()
    {

    }

    void PlayerScript::idle()
    {
        if (Input::GetKey(eKeyCode::LButton))
        {
        }

    }

    void PlayerScript::move()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (Input::GetKey(eKeyCode::Right))
        {
            pos.x += 100.f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::Left))
        {
            pos.x -= 100.f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::Up))
        {
            pos.y -= 100.f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::Down))
        {
            pos.y += 100.f * Time::DeltaTime();
        }
        tr->SetPosition(pos);
        if (Input::GetKeyUp(eKeyCode::Right)
            || Input::GetKeyUp(eKeyCode::Left)
            || Input::GetKeyUp(eKeyCode::Up)
            || Input::GetKeyUp(eKeyCode::Down))
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", false);
        }
    }

    void PlayerScript::giveWater()
    {
        if (mAnimator->IsComplete())
        {
            mState = eState::Idle;
            mAnimator->PlayAnimation(L"Idle", false);
        }
    }

}