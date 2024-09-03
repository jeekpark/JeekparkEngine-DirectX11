#pragma once


#include "jkCollider.h"


namespace jk
{
    class CircleCollider2D : public Collider
    {
    public:
        CircleCollider2D();
        ~CircleCollider2D();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render()  override;

    private:
        float mRadius;
    };

}
