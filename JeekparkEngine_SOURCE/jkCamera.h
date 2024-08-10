#pragma once

#include "jkComponent.h"


namespace jk
{
    using namespace jk::math;
    class Camera : public Component
    {
    public:
        Camera();
        ~Camera();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetTarget(GameObject* target) { mTarget = target; }

        Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };

    private:
        
        Vector2 mDistance;
        Vector2 mResolution;
        Vector2 mLookPosition;

        class GameObject* mTarget;
    };

}