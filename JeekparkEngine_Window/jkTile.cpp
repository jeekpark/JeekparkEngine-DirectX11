#include "jkTile.h"

#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"

namespace jk
{
    void Tile::Initialize()
    {
        GameObject::Initialize();
    }
    void Tile::Update()
    {
        GameObject::Update();
    }
    void Tile::LateUpdate()
    {
        GameObject::LateUpdate();
    }
    void Tile::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void Tile::SetPositionInGrid(int x, int y, Vector2 gridSize)
    {
        
        x = (int)(x / gridSize.x) * gridSize.x;
        y = (int)(y / gridSize.y) * gridSize.y;
        Transform* tr = GetComponent<Transform>();
        tr->SetPosition(Vector2(x, y));
    }
}