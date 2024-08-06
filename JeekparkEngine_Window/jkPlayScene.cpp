#include "jkPlayScene.h"

#include "jkGameObject.h"
#include "jkSpriteRenderer.h"
#include "jkTransform.h"
#include "jkPlayer.h"
#include "jkInput.h"
#include "jkTitleScene.h"
#include "jkSceneManager.h"
#include "jkObject.h"
#include "jkTexture.h"

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
        /*bg = new Player();
        Transform* tr = bg->AddComponent<Transform>();
        tr->SetName(L"TR");
        tr->SetPosition(Vector2(0, 0));

        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        sr->SetName(L"SR");
        sr->ImageLoad(L"C:\\Users\\9001\\Desktop\\CloudOcean.png");
        
        AddGameObject(bg, enums::eLayerType::Backgorund);*/

        bg = object::Instantiate<Player>(
            enums::eLayerType::Backgorund,
            math::Vector2(100, 100)
        );
        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        sr->SetName(L"SR");

        graphics::Texture* tex = new graphics::Texture();
        tex->Load(L"C:\\Users\\9001\\Desktop\\CloudOcean.png");
        //sr->ImageLoad(L"C:\\Users\\9001\\Desktop\\CloudOcean.png");

        Scene::Initialize();

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
    }
}
