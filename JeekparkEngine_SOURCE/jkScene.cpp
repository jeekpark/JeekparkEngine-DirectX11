#include "jkScene.h"

namespace jk
{
    Scene::Scene()
        : mLayers{}
    {
        mLayers.resize((UINT)eLayerType::Max);
        for (size_t i = 0; i < (UINT)eLayerType::Max; ++i)
        {
            mLayers[i] = new Layer();
        }
    }
    Scene::~Scene()
    {
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
    void Scene::OnEnter()
    {
    }
    void Scene::OnExit()
    {
    }
    void Scene::AddGameObject(GameObject* gameObject, eLayerType type)
    {
        mLayers[(UINT)type]->AddGameObject(gameObject);
    }

}