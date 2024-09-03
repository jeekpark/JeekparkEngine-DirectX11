#include "jkAnimator.h"

#include "jkResources.h"

namespace jk
{
    Animator::Animator()
        : Component(enums::eComponentType::Animator)
        , mAnimations{}
        , mActiveAnimation(nullptr)
        , mbLoop(false)
    {
    }
    Animator::~Animator()
    {
        for (auto& iter : mAnimations)
        {
            delete iter.second;
            iter.second = nullptr;
        }
        for (auto& iter : mEvents)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }
    void Animator::Initialize()
    {
    }
    void Animator::Update()
    {
        if (mActiveAnimation)
        {
            mActiveAnimation->Update();

            Events* events = FindEvents(mActiveAnimation->GetName());
            if (mActiveAnimation->IsComplete() == true)
            
            {
                if (events)
                {
                    events->completeEvent();
                }
                if (mbLoop == true)
                {
                    mActiveAnimation->Reset();
                }
            }
        }
    }
    void Animator::LateUpdate()
    {
    }
    void Animator::Render()
    {
        /*if (mActiveAnimation)
        {
            mActiveAnimation->Render(hdc);
        }*/
    }

    void Animator::CreateAnimation(
        const std::wstring& name,
        graphics::Texture* spriteSheet,
        Vector2 leftTop,
        Vector2 size,
        Vector2 offset,
        UINT spriteLength,
        float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);
        if (animation != nullptr)
        {
            return;
        }

        animation = new Animation();
        animation->SetName(name);
        animation->CreateAnimation(
            name,
            spriteSheet,
            leftTop,
            size,
            offset,
            spriteLength,
            duration
        );

        animation->SetAnimator(this);
        Events* events = new Events();
        mEvents.insert(std::make_pair(name, events));
        mAnimations.insert(std::make_pair(name, animation));
    }

    void Animator::CreateAnimationByFolder(
        /*const std::wstring& name,
        const std::wstring& path,
        Vector2 offset,
        float duration*/)
    {
        /*Animation* animation = nullptr;
        animation = FindAnimation(name);
        if (animation != nullptr)
        {
            return;
        }

        std::filesystem::path fs(path);
        std::vector<graphics::Texture*> images = {};
        for (auto& entry : std::filesystem::recursive_directory_iterator(fs))
        {
            std::wstring fileName = entry.path().filename();
            std::wstring fullName = entry.path();

            graphics::Texture* tex = Resources::Load<graphics::Texture>(fileName, fullName);
            images.push_back(tex);

        }

        UINT imageWidth = images[0]->GetWidth();
        UINT imageHeight = images[0]->GetHeight();
        UINT sheetWidth = imageWidth * images.size();
        UINT sheetHeight = imageHeight;
        graphics::Texture* spriteSheet = graphics::Texture::Create(name,
            sheetWidth, sheetHeight);

        for (size_t i = 0; i < images.size(); ++i)
        {
            BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0,
                imageWidth, imageHeight, images[i]->GetHdc(), 0, 0, SRCCOPY);
        }

        CreateAnimation(
            name,
            spriteSheet,
            { 0.f, 0.f },
            { (float)imageWidth, (float)imageHeight },
            { 0.f, 0.f },
            images.size(),
            duration
        );*/
    }
    Animation* Animator::FindAnimation(const std::wstring& name)
    {
        std::map<std::wstring, Animation*>& test = mAnimations;
        auto iter = mAnimations.find(name);
        if (iter == mAnimations.end())
        {
            return nullptr;
        }
        return iter->second;
        
    }
    void Animator::PlayAnimation(const std::wstring& name, bool loop, bool flip)
    {
        Animation* animation = FindAnimation(name);
        if (animation == nullptr)
        {
            return;
        }

        if (mActiveAnimation)
        {
            Events* currentEvents = FindEvents(mActiveAnimation->GetName());
            if (currentEvents)
            {
                currentEvents->endEvent();
            }
        }

        Events* nextEvents = FindEvents(animation->GetName());
        if (nextEvents)
        {
            nextEvents->startEvent();
        }

        animation->SetVerticalFlip(flip);
        mActiveAnimation = animation;
        mActiveAnimation->Reset();
        mbLoop = loop;
    }
    Animator::Events* Animator::FindEvents(const std::wstring& name)
    {
        auto iter = mEvents.find(name);
        if (iter == mEvents.end())
        {
            return nullptr;
        }
        return iter->second;
    }
    std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->startEvent.mEvent;
    }
    std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->completeEvent.mEvent;
    }
    std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->endEvent.mEvent;
    }
}