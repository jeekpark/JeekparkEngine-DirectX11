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
            obj->Update();
        }
    }
    void Layer::LateUpdate()
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->LateUpdate();
        }
    }
    void Layer::Render(HDC hdc)
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->Render(hdc);
        }
    }

    void Layer::AddGameObject(GameObject* gameObject)
    {
        mGameObjects.push_back(gameObject);
    }
}