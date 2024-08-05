#include "jkPlayScene.h"

#include "jkGameObject.h"
#include "jkSpriteRenderer.h"
#include "jkTransform.h"
#include "jkPlayer.h"
#include "jkInput.h"
#include "jkTitleScene.h"
#include "jkSceneManager.h"
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
        bg = new Player();
        Transform* tr = bg->AddComponent<Transform>();
        tr->SetName(L"TR");
        tr->SetPosition(Vector2(0, 0));

        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        sr->SetName(L"SR");
        sr->ImageLoad(L"C:\\Users\\9001\\Desktop\\CloudOcean.png");
        
        AddGameObject(bg, eLayerType::Backgorund);
    }
    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
        if (Input::GetKeyDown(eKeyCode::N))
        {
            SceneManager::LoadScene(L"TitleScene");
        }
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
        wchar_t str[50] = L"Play Scene";
        TextOut(hdc, 0, 0, str, wcsnlen_s(str, 50));
    }
    void PlayScene::OnEnter()
    {
    }
    void PlayScene::OnExit()
    {
        Transform* tr = bg->GetComponent<Transform>();
        tr->SetPosition(Vector2(0, 0));
    }
}
