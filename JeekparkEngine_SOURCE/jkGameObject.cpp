#include "jkGameObject.h"

#include "jkInput.h"
#include "jkTime.h"
#include "jkTransform.h"

namespace jk::object
{
    void Destory(GameObject* gameObject)
    {
        if (gameObject != nullptr)
            gameObject->death();
    }
}

namespace jk
{
    GameObject::GameObject()
        : mState(eState::Active)
        , mLayerType(enums::eLayerType::None)
    {
        mComponents.resize((UINT)enums::eComponentType::End);
        initializeTransform();
    }

    GameObject::~GameObject()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
            {
                continue;
            }
            delete comp;
            comp = nullptr;
        }
    }

    void GameObject::Initialize()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
            {
                continue;
            }
            comp->Initialize();
        }
    }

    void GameObject::Update()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
            {
                continue;
            }
            comp->Update();
        }
    }

    void GameObject::LateUpdate()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
            {
                continue;
            }
            comp->LateUpdate();
        }
    }

    void GameObject::Render()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
            {
                continue;
            }
            comp->Render();
        }
    }

    void GameObject::initializeTransform()
    {
        AddComponent<Transform>();
    }
}