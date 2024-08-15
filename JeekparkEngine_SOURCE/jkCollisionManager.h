#pragma once

#include "CommonInclude.h"
#include "jkCircleCollider2D.h"
#include "jkBoxCollider2D.h"
namespace jk
{
    using namespace enums;
    class CollisionManager
    {
    public:
        static void Initialize();
        static void Update();
        static void LateUpdate();
        static void Render(HDC hdc);

        static void CollistionLayerCheck(eLayerType left, eLayerType right, bool enable);
        static void LayerCollision(class Scene* scene, eLayerType row, eLayerType col);
        static void ColliderCollision(Collider* left, Collider* right);
    private:

        static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMaxtirx[(UINT)eLayerType::Max];
    };
}


