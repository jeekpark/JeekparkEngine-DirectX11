#include "jkToolScene.h"
#include "jkObject.h"
#include "jkTile.h"
#include "jkTilemapRenderer.h"
#include "jkResources.h"
#include "jkCamera.h"
#include "jkRenderer.h"
jk::ToolScene::ToolScene()
{
}

jk::ToolScene::~ToolScene()
{
}

void jk::ToolScene::Initialize()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
            TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
            tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
            tmr->SetTileSize({ 16.f, 16.f });
            
            tmr->SetIndex({ 0.f, 0.f });
            tile->GetComponent<Transform>()->SetPosition({ 16.f * 5.f * i, 16.f * 5.f * j });
            tile->GetComponent<Transform>()->SetScale({ 5.f, 5.f });
        }
    }
    Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
    TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
    tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
    tmr->SetTileSize({ 16.f, 16.f });
    tmr->SetIndex({ 0.f, 0.f });

    ///////// CAMERA /////////
    GameObject* camObj = object::Instantiate<GameObject>(enums::eLayerType::None);
    Camera* camComp = camObj->AddComponent<Camera>();
    renderer::mainCamera = camComp;

    Scene::Initialize();
}

void jk::ToolScene::Update()
{
    Scene::Update();
}

void jk::ToolScene::LateUpdate()
{
    Scene::LateUpdate();
}

void jk::ToolScene::Render(HDC hdc)
{
    Scene::Render(hdc);
}

void jk::ToolScene::OnEnter()
{
    Scene::OnEnter();
}

void jk::ToolScene::OnExit()
{
    Scene::OnExit();
}
