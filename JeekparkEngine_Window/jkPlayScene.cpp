#include "jkPlayScene.h"

#include "jkGameObject.h"
#include "jkSpriteRenderer.h"
#include "jkTransform.h"
#include "jkPlayer.h"

namespace jk
{
    PlayScene::PlayScene()
    {
    }
    PlayScene::~PlayScene()
    {
    }
    void PlayScene::Initialize()
    {
        Player* player = new Player();
        
        Transform* tr = player->AddComponent<Transform>();
        tr->SetPos(300, 300);
        tr->SetName(L"TR");

        SpriteRenderer* sp = player->AddComponent<SpriteRenderer>();
        sp->SetName(L"SR");

        AddGameObject(player);
    }
    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
}
