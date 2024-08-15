#include "jkCollisionManager.h"

#include "jkScene.h"
#include "jkSceneManager.h"
#include "jkGameObject.h"
#include "jkCollider.h"

namespace jk
{
    std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMaxtirx[(UINT)eLayerType::Max] = {};
    void CollisionManager::Initialize()
    {
    }
    void CollisionManager::Update()
    {
        for (UINT row = 0; row < (UINT)eLayerType::Max; ++row)
        {
            for (UINT col = row + 1; col < (UINT)eLayerType::Max; ++col)
            {
                if (mCollisionLayerMaxtirx[row][col] == true)
                {
                    LayerCollision(scene, (eLayerType)row, (eLayerType)col);
                }
            }
        }
    }
    void CollisionManager::LateUpdate()
    {
    }
    void CollisionManager::Render(HDC hdc)
    {
    }
    void CollisionManager::CollistionLayerCheck(eLayerType left, eLayerType right, bool enable)
    {
        int row = 0;
        int col = 0;

        if (left < right)
        {
            row = (int)left;
            col = (int)right;
        }
        else
        {
            row = (int)right;
            col = (int)left;
        }
        mCollisionLayerMaxtirx[row][col] = enable;
    }
    void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
    {
        const std::vector<GameObject*>& lefts = scene->GetLayer((eLayerType)left)->GetGameObjects();
        const std::vector<GameObject*>& rights = scene->GetLayer((eLayerType)right)->GetGameObjects();

        for (GameObject* left : lefts)
        {
            if (left->IsActive() == false)
            {
                continue;
            }
            Collider* leftCollider = left->GetComponent<Collider>();
            if (leftCollider == nullptr)
            {
                continue;
            }

            for (GameObject* right : rights)
            {
                if (right->IsActive() == false)
                {
                    continue;
                }
                Collider* rightCollider = right->GetComponent<Collider>();
                if (rightCollider == nullptr)
                {
                    continue;
                }
                if (left == right)
                {
                    continue;
                }

                ColliderCollision(leftCollider, rightCollider);
            }
        }
    }
    void CollisionManager::ColliderCollision(Collider* left, Collider* right)
    {

    }
}