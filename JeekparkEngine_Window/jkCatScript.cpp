#include "jkCatScript.h"

#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"
#include "jkGameObject.h"
#include "jkAnimator.h"
#include "jkObject.h"
namespace jk
{

    CatScript::CatScript()
        : mState(CatScript::eState::SitDown)
        , mAnimator(nullptr)
        , mTime(0.f)
        , mDirection(eDirection::Down)
        , mDeathTime(0.f)

    {
    }
    
    CatScript::~CatScript()
    {
    }

    void CatScript::Initialize()
    {
    }

    void CatScript::Update()
    {
        mDeathTime += Time::DeltaTime();
        if (mDeathTime > 3.f)
        {
            object::Destroy(GetOwner());
        }
        if (mAnimator == nullptr)
        {
            mAnimator = GetOwner()->GetComponent<Animator>();
        }
        switch (mState)
        {
        case jk::CatScript::eState::SitDown:
            sitDown();
            break;
        case jk::CatScript::eState::Walk:
            move();
            break;
        case jk::CatScript::eState::Sleep:
            break;
        case jk::CatScript::eState::LayDown:
            layDown();
            break;
        case jk::CatScript::eState::Attack:
            break;
        default:
            break;
        }

    }

    void CatScript::LateUpdate()
    {
    }

    void CatScript::Render(HDC hdc)
    {
    }

    void CatScript::sitDown()
    {
        
        mTime += Time::DeltaTime();

        if (mTime > 2.f)
        {
            object::Destroy(GetOwner());
        }

        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        Vector2 mousePos = Input::GetMousePostion();
        Transform* plTr = mPlayer->GetComponent<Transform>();

        Vector2 dest = mDest - plTr->GetPosition();
        pos += dest.normalize() * 700.f * Time::DeltaTime();

        tr->SetPosition(pos);
    }

    void CatScript::move()
    {
        mTime += Time::DeltaTime();
        if (mTime > 2.f)
        {
            int isLayDown = rand() % 2;

            if (isLayDown)
            {
                mState = eState::LayDown;
                mAnimator->PlayAnimation(L"LayDown", false);
                mTime = 0.f;
            }
            else
            {
                mState = eState::SitDown; 
                mAnimator->PlayAnimation(L"SitDown", false);
                mTime = 0.f;
            }
        }
        Transform* tr = GetOwner()->GetComponent<Transform>();
        translate(tr);

    }

    void CatScript::layDown()
    {

    }

    void CatScript::playWalkAnimationBydirection(eDirection dir)
    {
        switch (dir)
        {
        case eDirection::Left:
            mAnimator->PlayAnimation(L"LeftWalk", true);
            break;
        case eDirection::Right:
            mAnimator->PlayAnimation(L"RightWalk", true);
            break;
        case eDirection::Down:
            mAnimator->PlayAnimation(L"DownWalk", true);
            break;
        case eDirection::Up:
            mAnimator->PlayAnimation(L"UpWalk", true);
            break;
        default:
            assert(false);
            break;
        }
    }

    void CatScript::translate(Transform* tr)
    {
        Vector2 pos = tr->GetPosition();
        switch (mDirection)
        {
        case jk::CatScript::eDirection::Left:
            pos.x -= 100.f * Time::DeltaTime();
            break;
        case jk::CatScript::eDirection::Right:
            pos.x += 100.f * Time::DeltaTime();
            break;
        case jk::CatScript::eDirection::Down:
            pos.y += 100.f * Time::DeltaTime();
            break;
        case jk::CatScript::eDirection::Up:
            pos.y -= 100.f * Time::DeltaTime();
            break;
        default:
            assert(false);
            break;
        }

        tr->SetPosition(pos);
    }

}