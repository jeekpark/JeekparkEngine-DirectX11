#include "jkPlayer.h"

#include "jkInput.h"
#include "jkTransform.h"
#include "jkTime.h"

namespace jk
{
    void Player::Initialize()
    {
        GameObject::Initialize();
    }
    void Player::Update()
    {
        GameObject::Update();
    }
    void Player::LateUpdate()
    {
        GameObject::LateUpdate();
        if (Input::GetKey(eKeyCode::Right))
        {
            Transform* tr = GetComponent<Transform>();
            Vector2 pos = tr->GetPosition();
            pos.x += 100.f * Time::DeltaTime();
            tr->SetPosition(pos);

        }
    }
    void Player::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}