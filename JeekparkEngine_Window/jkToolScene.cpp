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
            tile->GetComponent<Transform>()->SetPosition({ 16.f * 3.f * i, 16.f * 3.f * j });
            tile->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
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
    //renderer::mainCamera = camComp;

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

    for (size_t i = 0; i < 50; ++i)
    {
        MoveToEx(hdc, 16 * 3 * i, 0, nullptr);
        LineTo(hdc, 16 * 3 * i, 1080);
    }
    for (size_t j = 0; j < 50; ++j)
    {
        MoveToEx(hdc, 0, 16 * 3 * j, nullptr);
        LineTo(hdc, 1920, 16 * 3 * j);
    }
}

void jk::ToolScene::OnEnter()
{
    Scene::OnEnter();
}

void jk::ToolScene::OnExit()
{
    Scene::OnExit();
}
