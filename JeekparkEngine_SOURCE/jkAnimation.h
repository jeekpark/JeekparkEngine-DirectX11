#pragma once

#include "jkResource.h"
#include "jkTexture.h"

namespace jk
{

    class Animation : public Resource
    {
    public:
        struct Sprite
        {
            Vector2 leftTop;
            Vector2 size;
            Vector2 offset;
            float duration;

            Sprite()
                : leftTop(Vector2::Zero)
                , size(Vector2::Zero)
                , offset(Vector2::Zero)
                , duration(0.f)
            {

            }
        };
        Animation();
        ~Animation();

        HRESULT Load(const std::wstring& path) override;

        void Update();
        void Render();

        void CreateAnimation(
            const std::wstring& name,
            graphics::Texture* spriteSheet,
            Vector2 leftTop,
            Vector2 size,
            Vector2 offset,
            UINT spriteLength,
            float duration);
        void Reset();

        bool IsComplete() const { return mbComplete; }
        void SetAnimator(class Animator* animator) { mAnimator = animator; }
        void SetVerticalFlip(bool verticalFlip) { mbVerticalFlip = verticalFlip; }
    private:
        class Animator* mAnimator;
        graphics::Texture* mTexture;
        std::vector<Sprite> mAnimationSheet;
        int mIndex;
        float mTime;
        bool mbComplete;
        bool mbVerticalFlip;
    };

}