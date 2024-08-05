#pragma once

#include "jkComponent.h"
#include "jkGameObject.h"
#include "jkLayer.h"
#include "jkScene.h"
#include "jkSceneManager.h"
#include "jkTransform.h"

namespace jk::object
{
    template <typename T>
    static T* Instantiate(enums::eLayerType type)
    {
        T* gameObject = new T();
        Scene* activeScene = SceneManager::GetActiveScene();
        Layer* layer = activeScene->GetLayer(type);
        layer->AddGameObject(gameObject);
        return gameObject;
    };

    template <typename T>
    static T* Instantiate(enums::eLayerType type, math::Vector2 position)
    {
        T* gameObject = new T();
        Scene* activeScene = SceneManager::GetActiveScene();
        Layer* layer = activeScene->GetLayer(type);
        layer->AddGameObject(gameObject);

        Transform* tr = gameObject->GetComponent<Transform>();
        tr->SetPosition(position);

        return gameObject;
    };
}