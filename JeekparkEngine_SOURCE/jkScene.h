#pragma once

#include "jkEntity.h"
#include "jkGameObject.h"
#include "jkLayer.h"

namespace jk
{

    class Scene : public Entity
    {
    public:
        Scene();
        ~Scene();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);

        virtual void OnEnter();
        virtual void OnExit();

        void AddGameObject(GameObject* gameObject, eLayerType type);
    private:
        std::vector<Layer*> mLayers;
    };

}

