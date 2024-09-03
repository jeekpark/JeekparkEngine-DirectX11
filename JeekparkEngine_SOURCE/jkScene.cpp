#include "jkScene.h"

#include "jkCollisionManager.h"
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
    void Scene::Render()
    {
        for (Layer* layer : mLayers)
        {
            layer->Render();
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
        CollisionManager::Clear();
    }
    void Scene::AddGameObject(GameObject* gameObject, enums::eLayerType type)
    {
        mLayers[(UINT)type]->AddGameObject(gameObject);
    }
    void Scene::EraseGameObject(GameObject* gameObject)
    {
        enums::eLayerType type = gameObject->GetLayerType();
        mLayers[(UINT)type]->EraseGameObject(gameObject);
    }

}