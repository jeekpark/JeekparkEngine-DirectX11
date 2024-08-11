#include "jkPlayerScript.h"

#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
#include "jkGameObject.h"
#include "jkAnimator.h"
#include "jkCat.h"
#include "jkCatScript.h"
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
        Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
        
        CatScript* catScript = cat->AddComponent<CatScript>();
        catScript->SetPlayer(GetOwner());
        graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
        Animator* catAnimator = cat->AddComponent<Animator>();
        catAnimator->CreateAnimation(L"DownWalk", catTex,
            Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"RightWalk", catTex,
            Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"UpWalk", catTex,
            Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"LeftWalk", catTex,
            Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"SitDown", catTex,
            Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
        catAnimator->CreateAnimation(L"Grooming", catTex,
            Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
        catAnimator->CreateAnimation(L"LayDown", catTex,
            Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);

        catAnimator->PlayAnimation(L"SitDown", false);

        Transform* tr = GetOwner()->GetComponent<Transform>();

        cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
        cat->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
    }

    void PlayerScript::idle()
    {
        if (Input::GetKey(eKeyCode::LButton))
        {
            mState = PlayerScript::eState::GiveWater;
            mAnimator->PlayAnimation(L"FrontGiveWater", false);
            Vector2 mousePos = Input::GetMousePostion();
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