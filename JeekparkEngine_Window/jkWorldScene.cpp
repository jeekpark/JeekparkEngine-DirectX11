#include "jkWorldScene.h"

#include "jkApplication.h"
#include "jkCamera.h"
#include "jkObject.h"
#include "jkRenderer.h"
#include "jkResources.h"
#include "jkTexture.h"
#include "jkAnimator.h"
#include "jkBoxCollider2D.h"
#include "jkRigidbody.h"
#include "jkInput.h"
#include "jkSceneManager.h"

#include "jkHero.h"

extern jk::Application app;

namespace jk
{
    WorldScene::WorldScene()
    {
    }
    WorldScene::~WorldScene()
    {
        
        
    }
    void WorldScene::Initialize()
    {
        //initCamera();
        //initPlayableHero();

        Scene::Initialize();
    }
    void WorldScene::Update()
    {
        Scene::Update();
    }
    void WorldScene::LateUpdate()
    {
        Scene::LateUpdate();
        if (Input::GetKeyDown(eKeyCode::N))
        {
            SceneManager::LoadScene(L"TitleScene");
        }
    }
    void WorldScene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t str[50] = L"World Scene";
        TextOut(hdc, 0, 0, str, (int)wcsnlen_s(str, 50));
    }
    void WorldScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void WorldScene::OnExit()
    {
        Scene::OnExit();
    }
    void WorldScene::initCamera()
    {
        GameObject* cameraObj = object::Instantiate<GameObject>(
            enums::eLayerType::None,
            { app.GetClientWidth() / 2.f, app.GetClientHeight() / 2.f }
        );
        Camera* cameraComp = cameraObj->AddComponent<Camera>();
        renderer::mainCamera = cameraComp;
    }
    void WorldScene::initPlayableHero()
    {
        Hero* hero = object::Instantiate<Hero>(enums::eLayerType::Player);
        renderer::mainCamera->SetTarget(hero);
        hero->GetComponent<Transform>()->SetPosition({ 200.f, 600.f });
        hero->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
        hero->GetComponent<Transform>()->SetRotation(0.f);
        
        hero->SetLevel(1);
        hero->SetExperience(0);
        hero->SetHealth(438);
        hero->SetMaxHealth(438);
        hero->SetMana(308);
        hero->SetMaxMana(308);
        hero->SetStrength(19);
        hero->SetIntelligence(14);
        hero->SetAgility(19);
        hero->SetArmor(1.33f);
        hero->SetMagicResist(26.9f / 100.f);
        hero->SetAttackDamage(37);
        hero->SetAttackRate(0.67f);
        hero->SetAttackRange(600);
        hero->SetAttackSpeed(100);
        hero->SetPreAttackTime(0.4f);
        hero->SetAttackTime(0.6f);
        hero->SetPostAttackTime(0.7f);
        hero->SetProjectileSpeed(900);
        hero->SetTurnTime(0.6f);
        hero->SetVisionRange(1800);
        hero->SetGold(450);

        graphics::Texture* heroTex = Resources::Find<graphics::Texture>(L"SakuyaTexture");
        Animator* heroAnimator = hero->AddComponent<Animator>();
        heroAnimator->CreateAnimation(L"Idle", heroTex,
            { 0.f, 0.f }, { 64.f, 64.f }, { 32.f, 64.f }, 6, 0.1f);
        heroAnimator->PlayAnimation(L"Idle", true);

        BoxCollider2D* boxCollider2d = hero->AddComponent<BoxCollider2D>();
        boxCollider2d->SetOffset({ -64.f * 3.f / 2.f, -64.f * 3.f });
        boxCollider2d->SetSize({ 64.f * 3.f, 64.f * 3.f });

    }
}
