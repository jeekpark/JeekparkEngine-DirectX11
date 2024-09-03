#include "jkAnimation.h"

#include "jkTime.h"
#include "jkTransform.h"
#include "jkGameObject.h"
#include "jkAnimator.h"
#include "jkRenderer.h"
#include "jkCamera.h"

namespace jk
{
    Animation::Animation()
        : Resource(enums::eResourceType::Animation)
        , mAnimator(nullptr)
        , mTexture(nullptr)
        , mAnimationSheet{}
        , mIndex(-1)
        , mTime(0.f)
        , mbComplete(false)
        , mbVerticalFlip(false)
    {
    }
    Animation::~Animation()
    {
    }
    HRESULT Animation::Load(const std::wstring& path)
    {
        return E_NOTIMPL;
    }
    void Animation::Update()
    {
        if (mbComplete)
        {
            return;
        }

        mTime += Time::DeltaTime();

        if (mAnimationSheet[mIndex].duration < mTime)
        {
            mTime = 0.f;
            if (mIndex < mAnimationSheet.size() - 1)
            {
                ++mIndex;
            }
            else
            {
                mbComplete = true;
            }
        }
    }
    void Animation::Render()
    {
        assert(mTexture != nullptr);
    }
    void Animation::CreateAnimation(
        const std::wstring& name,
        graphics::Texture* spriteSheet,
        Vector2 leftTop,
        Vector2 size, 
        Vector2 offset, 
        UINT spriteLength, 
        float duration)
    {
        SetName(name);
        mTexture = spriteSheet;
        for (size_t i = 0; i < spriteLength; ++i)
        {
            Sprite sprite = {};
            sprite.leftTop.x = leftTop.x + (size.x * i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mAnimationSheet.push_back(sprite);
        }
    }
    void Animation::Reset()
    {
        mTime = 0.f;
        mIndex = 0;
        mbComplete = false;
    }
}