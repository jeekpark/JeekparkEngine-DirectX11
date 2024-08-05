#pragma once

#include "jkEntity.h"
#include "jkGameObject.h"

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

        void AddGameObject(GameObject* gameObject);
    private:
        std::vector<GameObject*> mGameObjects;
    };

}

