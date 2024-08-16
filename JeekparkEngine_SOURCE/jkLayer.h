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
        void EraseGameObject(GameObject* gameObject);
        const std::vector<GameObject*> GetGameObjects() const { return mGameObjects; }
    private:
        void findDeadGameObject(OUT std::vector<GameObject*>& gameObjects);
        void deleteGameObject(std::vector<GameObject*>& deadGameObjects);
        void eraseDeadGameObject();

        std::vector<GameObject*> mGameObjects;
    };

    typedef std::vector<GameObject*>::iterator GameObjectIter;

}