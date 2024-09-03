#pragma once
#include "CommonInclude.h"

#include "jkComponent.h"


namespace jk
{
    class GameObject : public Entity
    {
    public:


        enum class eState
        {
            Active,
            Paused,
            Dead,
            End
        };
        GameObject();
        ~GameObject();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render();

        template<typename T>
        T* AddComponent()
        {
            T* comp = new T();
            comp->SetOwner(this);
            mComponents[(UINT)comp->GetComponentType()] = comp;
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

        eState GetState() const { return mState; }

        void SetActive(bool power)
        {
            if (power == true)
            {
                mState = eState::Active;
            }
            else
            {
                mState = eState::Paused;
            }
        }
        bool IsActive() const { return mState == eState::Active; }
        bool IsDead() const { return mState == eState::Dead; }
        void Death() { mState = eState::Dead; }
        void SetLayerType(enums::eLayerType layer) { mLayerType = layer; }
        enums::eLayerType GetLayerType() const { return mLayerType; }
    private:
        void initializeTransform();
        
        

    private:
        std::vector<Component*> mComponents;
        eState mState;
        enums::eLayerType mLayerType;
    };

}

