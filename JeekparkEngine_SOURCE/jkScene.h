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
        virtual void Destroy();

        virtual void OnEnter();
        virtual void OnExit();

        void AddGameObject(GameObject* gameObject, enums::eLayerType type);
        Layer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type]; }
    private:
        std::vector<Layer*> mLayers;
    };

}

