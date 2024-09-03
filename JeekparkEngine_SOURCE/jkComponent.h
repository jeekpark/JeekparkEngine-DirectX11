#pragma once

#include "jkEntity.h"

namespace jk
{
    class GameObject;
    class Component : public Entity
    {
    public:
        Component(enums::eComponentType type);
        virtual ~Component();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render();

        void SetOwner(GameObject* owner) { mOwner = owner; }
        GameObject* GetOwner() { return mOwner; }
        enums::eComponentType GetComponentType() const { return mComponentType; }

    private:
        GameObject* mOwner;
        enums::eComponentType mComponentType;
    };

}

