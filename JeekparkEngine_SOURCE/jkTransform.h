#pragma once

#include "jkComponent.h"

namespace jk
{
    class Transform : public Component
    {
    public:
        Transform();
        ~Transform();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        Vector2 GetPosition() const { return mPosition; }
        Vector2 GetScale() const { return mScale; }
        float GetRotation() const { return mRotation; }
        
        void SetPosition(const Vector2& pos) { mPosition = pos; }
        void SetScale(const Vector2& scl) { mScale = scl; }
        void SetRotation(float rot) { mRotation = rot; }
        

    private:
        Vector2 mPosition;
        Vector2 mScale;
        float mRotation;
    };

}

