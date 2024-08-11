#include "jkScene.h"

namespace jk
{
    Scene::Scene()
        : mLayers{}
    {
        mLayers.resize((UINT)enums::eLayerType::Max);
        for (size_t i = 0; i < (UINT)enums::eLayerType::Max; ++i)
        {
            mLayers[i] = new Layer();
        }
    }
    Scene::~Scene()
    {
        for (Layer* layer : mLayers)
        {
            delete layer;
        }
    }
    void Scene::Initialize()
    {
        for (Layer* layer : mLayers)
        {
            layer->Initialize();
        }
    }
    void Scene::Update()
    {
        for (Layer* layer : mLayers)
        {
            layer->Update();
        }
    }
    void Scene::LateUpdate()
    {
        for (Layer* layer : mLayers)
        {
            layer->LateUpdate();
        }
    }
    void Scene::Render(HDC hdc)
    {
        for (Layer* layer : mLayers)
        {
            layer->Render(hdc);
        }
    }
    void Scene::Destroy()
    {
        for (Layer* layer : mLayers)
        {
            layer->Destroy();
        }
    }
    void Scene::OnEnter()
    {
    }
    void Scene::OnExit()
    {
    }
    void Scene::AddGameObject(GameObject* gameObject, enums::eLayerType type)
    {
        mLayers[(UINT)type]->AddGameObject(gameObject);
    }

}