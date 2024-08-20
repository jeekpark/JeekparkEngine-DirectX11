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
#include "jkBoxCollider2D.h"
#include "jkSakuya.h"
#include "jkSakuyaScript.h"
#include "jkApplication.h"
#include "jkCollisionManager.h"
#include "jkRigidbody.h"
#include "jkFloor.h"
#include "jkFloorScript.h"
extern jk::Application app;

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
            { app.GetClientWidth() / 2.f, app.GetClientHeight() / 2.f}
        );
        Camera* cameraComp = cameraObj->AddComponent<Camera>();
        renderer::mainCamera = cameraComp;

         /////// SAKUYA ////////
        Sakuya* sakuya = object::Instantiate<Sakuya>(enums::eLayerType::Player);
        renderer::mainCamera->SetTarget(sakuya);
        sakuya->GetComponent<Transform>()->SetPosition({ 200.f, 600.f });
        sakuya->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
        sakuya->GetComponent<Transform>()->SetRotation(0.f);
        SakuyaScript* sakuyaScript = sakuya->AddComponent<SakuyaScript>();
        graphics::Texture* sakuyaTex = Resources::Find<graphics::Texture>(L"SakuyaTexture");
        Animator* sakuyaAnimator = sakuya->AddComponent<Animator>();
        sakuyaAnimator->CreateAnimation(L"Idle", sakuyaTex,
            { 0.f, 0.f }, { 64.f, 64.f }, { 32.f, 64.f }, 6, 0.1f);
        sakuyaAnimator->CreateAnimation(L"StartRun", sakuyaTex,
            { 64.f * 9.f, 0.f }, { 64.f, 64.f }, { 32.f, 64.f }, 8, 0.01f);
        sakuyaAnimator->CreateAnimation(L"Run", sakuyaTex,
            { 0.f, 64.f * 1.f }, { 64.f, 64.f }, { 32.f, 64.f }, 16, 0.03f);
        sakuyaAnimator->CreateAnimation(L"EndRun", sakuyaTex,
            { 0.f, 64.f * 2.f }, { 64.f, 64.f }, { 32.f, 64.f }, 8, 0.03f);
        sakuyaAnimator->PlayAnimation(L"Idle", true);
        BoxCollider2D* boxCollider2d = sakuya->AddComponent<BoxCollider2D>();
        boxCollider2d->SetOffset({ -64.f * 3.f / 2.f, -64.f * 3.f });
        boxCollider2d->SetSize({ 64.f * 3.f, 64.f * 3.f });
        Rigidbody* rgd = sakuya->AddComponent<Rigidbody>();



        Sakuya* npc = object::Instantiate<Sakuya>(enums::eLayerType::Player);
        npc->GetComponent<Transform>()->SetPosition({ 500.f, 640.f });
        npc->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
        Animator* npcAnimator = npc->AddComponent<Animator>();
        npcAnimator->CreateAnimation(L"Idle", sakuyaTex,
            { 0.f, 0.f }, { 64.f, 64.f }, { 32.f, 64.f }, 6, 0.1f);
        npcAnimator->PlayAnimation(L"Idle", true);
        BoxCollider2D* npcCollider2d = npc->AddComponent<BoxCollider2D>();
        npcCollider2d->SetOffset({ -64.f * 3.f / 2.f, -64.f * 3.f });
        npcCollider2d->SetSize({ 64.f * 3.f, 64.f * 3.f });
        //Rigidbody* npcRgd = npc->AddComponent<Rigidbody>();
   
        /////// FLOOR ////////
        GameObject* floor = object::Instantiate<GameObject>(enums::eLayerType::Floor, {0.f, 800.f});
        BoxCollider2D* floorCollider = floor->AddComponent<BoxCollider2D>();
        floorCollider->SetSize({ 1000.f, 10.f });
        floor->AddComponent<FloorScript>();

        Scene::Initialize();
        object::DontDestroyOnLoad(sakuya);
        
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
        Scene::OnEnter();
        CollisionManager::CollistionLayerCheck(eLayerType::Player, eLayerType::Player, true);
        CollisionManager::CollistionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
    }
    void PlayScene::OnExit()
    {
        Scene::OnExit();
    }
}
