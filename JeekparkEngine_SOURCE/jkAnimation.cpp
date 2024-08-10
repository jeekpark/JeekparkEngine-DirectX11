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
    void Animation::Render(HDC hdc)
    {
        assert(mTexture != nullptr);

        GameObject* obj = mAnimator->GetOwner();
        Transform* tr = obj->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        Vector2 scl = tr->GetScale();
        float rot = tr->GetRotation();
        Sprite sprite = mAnimationSheet[mIndex];

        graphics::Texture::eTextureType type = mTexture->GetTextureType();
        if (type == graphics::Texture::eTextureType::Bmp)
        {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            func.SourceConstantAlpha = 255;

            
            HDC imgHdc = mTexture->GetHdc();
            AlphaBlend(hdc,
                pos.x - (sprite.size.x / 2.f),
                pos.y - (sprite.size.y / 2.f),
                sprite.size.x * scl.x,
                sprite.size.y * scl.y,
                imgHdc,
                sprite.leftTop.x,
                sprite.leftTop.y,
                sprite.size.x,
                sprite.size.y,
                func
            );
        }
        else if (type == graphics::Texture::eTextureType::Png)
        {
            Gdiplus::ImageAttributes imgAtt = {};
            imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
            Gdiplus::Graphics graphics(hdc);

            graphics.TranslateTransform(pos.x, pos.y);
            graphics.RotateTransform(rot);
            graphics.TranslateTransform(-pos.x, -pos.y);

            graphics.DrawImage(
                mTexture->GetImage(),
                Gdiplus::Rect(
                    pos.x - (sprite.size.x / 2.f),
                    pos.y - (sprite.size.y / 2.f),
                    sprite.size.x * scl.x,
                    sprite.size.y * scl.y
                ),
                sprite.leftTop.x,
                sprite.leftTop.y,
                sprite.size.x,
                sprite.size.y,
                Gdiplus::UnitPixel,
                &imgAtt
            );
        }

        if (renderer::mainCamera)
        {
            pos = renderer::mainCamera->CalculatePosition(pos);
        }

        


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