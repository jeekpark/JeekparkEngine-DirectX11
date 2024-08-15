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
    void Animation::Render(HDC hdc)
    {
        assert(mTexture != nullptr);

        GameObject* obj = mAnimator->GetOwner();
        Transform* tr = obj->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        Vector2 scl = tr->GetScale();
        float rot = tr->GetRotation();

        if (renderer::mainCamera)
        {
            pos = renderer::mainCamera->CalculatePosition(pos);
        }

        Sprite sprite = mAnimationSheet[mIndex];

        graphics::Texture::eTextureType type = mTexture->GetTextureType();
        if (type == graphics::Texture::eTextureType::Bmp)
        {
            HDC imgHdc = mTexture->GetHdc();

            XFORM xForm;
            float radians = rot * (3.14159265f / 180.0f);
            xForm.eM11 = cos(radians);
            xForm.eM12 = sin(radians);
            xForm.eM21 = -sin(radians);
            xForm.eM22 = cos(radians);
            xForm.eDx = pos.x;
            xForm.eDy = pos.y;

            SetGraphicsMode(hdc, GM_ADVANCED);
            SetWorldTransform(hdc, &xForm);

            if (mTexture->IsAlpha())
            {
                BLENDFUNCTION func = {};
                func.BlendOp = AC_SRC_OVER;
                func.BlendFlags = 0;
                func.AlphaFormat = AC_SRC_ALPHA;
                func.SourceConstantAlpha = 255;

                AlphaBlend(hdc,
                    (int)-sprite.offset.x * scl.x,
                    (int)-sprite.offset.y * scl.y,
                    (int)sprite.size.x * scl.x,
                    (int)sprite.size.y * scl.y,
                    imgHdc,
                    (int)sprite.leftTop.x,
                    (int)sprite.leftTop.y,
                    (int)sprite.size.x,
                    (int)sprite.size.y,
                    func
                );
            }
            else
            {
                TransparentBlt(hdc,
                    -sprite.offset.x * scl.x,
                    -sprite.offset.y * scl.y,
                    sprite.size.x * scl.x,
                    sprite.size.y * scl.y,
                    imgHdc,
                    sprite.leftTop.x,
                    sprite.leftTop.y,
                    sprite.size.x,
                    sprite.size.y,
                    RGB(255, 0, 255)
                );
            }
            ModifyWorldTransform(hdc, NULL, MWT_IDENTITY);
            Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);

        }
        else if (type == graphics::Texture::eTextureType::Png)
        {
            Gdiplus::ImageAttributes imgAtt = {};
            //imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
            Gdiplus::Graphics graphics(hdc);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);

            graphics.TranslateTransform(pos.x, pos.y);
            graphics.RotateTransform(rot);
            graphics.TranslateTransform(-pos.x, -pos.y);

            if (mbVerticalFlip)
            {
                graphics.TranslateTransform(pos.x, 0);
                graphics.ScaleTransform(-1.0f, 1.0f);
                graphics.TranslateTransform(-pos.x - sprite.size.x * scl.x, 0);
                sprite.offset.x *= -1;
            }
            
            graphics.DrawImage(
                mTexture->GetImage(),
                Gdiplus::Rect(
                    pos.x - sprite.offset.x * scl.x,
                    pos.y - sprite.offset.y * scl.y,
                    sprite.size.x * scl.x,
                    sprite.size.y * scl.y
                ),
                sprite.leftTop.x,
                sprite.leftTop.y,
                sprite.size.x,
                sprite.size.y,
                Gdiplus::UnitPixel,
                nullptr//&imgAtt
            );
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