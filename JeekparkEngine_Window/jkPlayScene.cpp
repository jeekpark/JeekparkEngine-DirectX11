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
#include "jkResources.h"
#include "jkPlayerScript.h"
#include "jkCamera.h"
#include "jkRenderer.h"
#include "jkAnimator.h"

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
        GameObject* camera = object::Instantiate<GameObject>(
            enums::eLayerType::None,
            {347.f, 450.f}
        );
        Camera* cameraComp = camera->AddComponent<Camera>();
        renderer::mainCamera = cameraComp;
        //camera->AddComponent<PlayerScript>();

        mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
        //SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
        //sr->SetSize(Vector2(3.f, 3.f));
        mPlayer->AddComponent<PlayerScript>();

        graphics::Texture* pacmanTexture = Resources::Find<graphics::Texture>(L"Cat");
        Animator* animator = mPlayer->AddComponent<Animator>();
        animator->CreateAnimation(L"CatFrontMove", pacmanTexture,
            Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 1);
        animator->PlayAnimation(L"CatFrontMove");
        //sr->SetTexture(pacmanTexture);
        

        GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Backgorund);
        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        sr->SetSize({ 3.f, 3.f });
        
        graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
        
        sr->SetTexture(bgTexture);


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
        //wchar_t str[50] = L"Play Scene";
        //TextOut(hdc, 0, 0, str, (int)wcsnlen_s(str, 50));
    }
    void PlayScene::OnEnter()
    {
    }
    void PlayScene::OnExit()
    {
    }
}
