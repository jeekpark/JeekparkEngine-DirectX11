#include "jkScene.h"

namespace jk
{
    Scene::Scene()
        : mGameObjects{}
    {
    }
    Scene::~Scene()
    {
    }
    void Scene::Initialize()
    {
    }
    void Scene::Update()
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->Update();
        }
    }
    void Scene::LateUpdate()
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->LateUpdate();
        }
    }
    void Scene::Render(HDC hdc)
    {
        for (GameObject* obj : mGameObjects)
        {
            obj->Render(hdc);
        }
    }
    void Scene::AddGameObject(GameObject* gameObject)
    {
        mGameObjects.push_back(gameObject);
    }
}