#pragma once

#include "jkCollider.h"

namespace jk
{
    class BoxCollider2D : public Collider
    {
    public:
        BoxCollider2D();
        ~BoxCollider2D();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render(HDC hdc)  override;

        void SetSize(Vector2 size) { mSize = size; }
        Vector2 GetSize() { return mSize; }

    private:
        Vector2 mSize;
        

    };
}
