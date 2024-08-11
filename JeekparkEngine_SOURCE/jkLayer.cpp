#include "jkLayer.h"

namespace jk
{
    Layer::Layer()
    {
    }
    Layer::~Layer()
    {
        for (GameObject* obj : mGameObjects)
        {

            delete obj;
        }
    }

    void Layer::Initialize()
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->Initialize();
        }
    }
    void Layer::Update()
    {
        for (GameObject* obj : mGameObjects)
        {
            GameObject::eState state = obj->GetActive();
            if (state == GameObject::eState::Paused ||
                state == GameObject::eState::Dead)
            {
                continue;
            }
            obj->Update();
        }
    }
    void Layer::LateUpdate()
    {
        for (GameObject* obj : mGameObjects)
        {
            GameObject::eState state = obj->GetActive();
            if (state == GameObject::eState::Paused ||
                state == GameObject::eState::Dead)
            {
                continue;
            }
            obj->LateUpdate();
        }
    }
    void Layer::Render(HDC hdc)
    {
        for (GameObject* obj : mGameObjects)
        {
            GameObject::eState state = obj->GetActive();
            if (state == GameObject::eState::Paused ||
                state == GameObject::eState::Dead)
            {
                continue;
            }
            obj->Render(hdc);
        }
    }
    void Layer::Destroy()
    {
        for (GameObjectIter iter = mGameObjects.begin();
            iter != mGameObjects.end(); )
        {
            GameObject::eState active = (*iter)->GetActive();
            if (active == GameObject::eState::Dead)
            {
                GameObject* obj = (*iter);
                iter = mGameObjects.erase(iter);
                delete obj;
                obj = nullptr;
                continue;
            }
            iter++;
        }
    }

    void Layer::AddGameObject(GameObject* gameObject)
    {
        mGameObjects.push_back(gameObject);
    }
}