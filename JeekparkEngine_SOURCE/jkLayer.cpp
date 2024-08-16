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
            GameObject::eState state = obj->GetState();
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
            GameObject::eState state = obj->GetState();
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
            GameObject::eState state = obj->GetState();
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
        std::vector<GameObject*> deadGameObjects = {};
        findDeadGameObject(deadGameObjects);
        eraseDeadGameObject();
        deleteGameObject(deadGameObjects);
    }

    void Layer::AddGameObject(GameObject* gameObject)
    {
        assert(gameObject != nullptr);
        mGameObjects.push_back(gameObject);
    }
    void Layer::EraseGameObject(GameObject* gameObject)
    {
        std::erase_if(mGameObjects,
            [=](GameObject* obj)
            {
                return obj == gameObject;
            });
    }
    void Layer::findDeadGameObject(OUT std::vector<GameObject*>& gameObjects)
    {
        for (GameObject* obj : mGameObjects)
        {
            GameObject::eState active = obj->GetState();
            if (active == GameObject::eState::Dead)
            {
                gameObjects.push_back(obj);
            }
        }
    }

    void Layer::deleteGameObject(std::vector<GameObject*>& deadGameObjects)
    {
        for (GameObject* obj : deadGameObjects)
        {
            delete obj;
        }
    }
    void Layer::eraseDeadGameObject()
    {
        std::erase_if(mGameObjects
            , [](GameObject* obj)
            {
                return obj->GetState() == GameObject::eState::Dead;
            });
    }
}