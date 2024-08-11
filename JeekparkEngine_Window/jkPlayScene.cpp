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
#include "jkCat.h"
#include "jkCatScript.h"

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
        GameObject* cameraObj = object::Instantiate<GameObject>(
            enums::eLayerType::None,
            { 0.f, 0.f }//{347.f, 450.f}
        );
        Camera* cameraComp = cameraObj->AddComponent<Camera>();
        renderer::mainCamera = cameraComp;


        /////// PLAYER ////////
        mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
        mPlayer->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
        PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
        graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
        Animator* playerAnimator = mPlayer->AddComponent<Animator>();
        playerAnimator->CreateAnimation(L"Idle", playerTex,
            Vector2(2000.f, 250.f), Vector2(250.f, 250.f), Vector2::Zero, 1, 0.1f);
        playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex,
            Vector2(0.f, 8.f * 250.f), Vector2(250.f, 250.f), Vector2::Zero, 12, 0.1f);
        
        playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

        

        playerAnimator->PlayAnimation(L"Idle", false);


        /////// SAKUYA ////////
        Player* sakuya = object::Instantiate<Player>(enums::eLayerType::Player);
        graphics::Texture* sakuyaTex = Resources::Find<graphics::Texture>(L"Sakuya");
        Animator* sakuyaAnimator = sakuya->AddComponent<Animator>();
        sakuyaAnimator->CreateAnimation(L"Idle", sakuyaTex,
            { 0.f, 0.f }, { 64.f, 64.f }, { 0.f, 0.f }, 6, 0.1f);
        sakuyaAnimator->CreateAnimation(L"Float", sakuyaTex,
            { 0.f, 64.f * 9.f }, { 64.f, 64.f }, { 0.f, 0.f }, 5, 0.05f);
        sakuya->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
        sakuya->GetComponent<Transform>()->SetScale({ 1.f, 1.f });
        sakuyaAnimator->PlayAnimation(L"Float", true);

        /////// CAT ////////
        //Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
        //cat->AddComponent<CatScript>();
        ////cameraComp->SetTarget(cat);
        //graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
        //Animator* catAnimator = cat->AddComponent<Animator>();
        /*catAnimator->CreateAnimation(L"DownWalk", catTex,
            Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"RightWalk", catTex,
            Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"UpWalk", catTex,
            Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"LeftWalk", catTex,
            Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.2f);
        catAnimator->CreateAnimation(L"SitDown", catTex,
            Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
        catAnimator->CreateAnimation(L"Grooming", catTex,
            Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
        catAnimator->CreateAnimation(L"LayDown", catTex,
            Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);*/

        //catAnimator->PlayAnimation(L"SitDown", false);
        /*catAnimator->CreateAnimationByFolder(L"MushroomIdle",
            L"..\\Resources\\Mushroom", {0.f, 0.f}, .5f);
        catAnimator->PlayAnimation(L"MushroomIdle", true);
        cat->GetComponent<Transform>()->SetPosition({ 200, 200 });
        cat->GetComponent<Transform>()->SetScale({ 2.f, 2.f });*/
        
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
