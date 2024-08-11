#pragma once

#include "jkEntity.h"
#include "jkGameObject.h"

namespace jk
{
    class Layer : public Entity
    {
    public:
        Layer();
        ~Layer();


        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);
        virtual void Destroy();

        void AddGameObject(GameObject* gameObject);
    private:
        //eLayerType mType;
        std::vector<GameObject*> mGameObjects;
    };

    typedef std::vector<GameObject*>::iterator GameObjectIter;

}