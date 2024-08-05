#pragma once
#include "CommonInclude.h"

#include "jkComponent.h"

namespace jk
{
    class GameObject
    {
    public:
        GameObject();
        ~GameObject();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);

        template<typename T>
        T* AddComponent()
        {
            T* comp = new T();
            comp->SetOwner(this);
            mComponents.push_back(comp);
            return comp;
        }

        template<typename T>
        T* GetComponent()
        {
            T* res = nullptr;
            for (Component* comp : mComponents)
            {
                res = dynamic_cast<T*>(comp);
                if (res)
                {
                    break;
                }
            }
            return res;
        }


    private:
        std::vector<Component*> mComponents;
    };

}

