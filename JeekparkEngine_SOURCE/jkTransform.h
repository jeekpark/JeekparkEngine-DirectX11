#pragma once

#include "jkComponent.h"

namespace jk
{
    using namespace math;

    class Transform : public Component
    {
    public:
        Transform();
        ~Transform();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetPosition(const Vector2& pos)
        {
            mPosition = pos;
        }

        const Vector2& GetPosition() const
        {
            return mPosition;
        }

    private:
        Vector2 mPosition;
    };

}

