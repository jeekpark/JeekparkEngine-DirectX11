#pragma once

#include "jkComponent.h"

namespace jk
{
    class Collider : public Component
    {
    public:

        Collider();
        ~Collider();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render(HDC hdc)  override;

        virtual void OnCollisionEnter(Collider* other);
        virtual void OnCollisionStay(Collider* other);
        virtual void OnCollisionExit(Collider* other);

        Vector2 GetOffset() { return mOffset; }
        void SetOffset(Vector2 offset) { mOffset = offset; }

        UINT32 GetID() { return mID; }
        Vector2 GetSize() { return mSize; }
        void SetSize(Vector2 size) { mSize = size; }

    private:
        static UINT32 sCollistionID;
        UINT32 mID;
        Vector2 mOffset;
        Vector2 mSize;
    };

}

