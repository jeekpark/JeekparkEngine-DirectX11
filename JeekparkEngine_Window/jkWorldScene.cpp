#include "jkWorldScene.h"

#include "jkApplication.h"
#include "jkCamera.h"
#include "jkObject.h"
#include "jkRenderer.h"
#include "jkResources.h"
#include "jkTexture.h"

#include "jkInput.h"
#include "jkSceneManager.h"

#include "jkHero.h"
#include "jkSpriteRenderer.h"
extern jk::Application app;

namespace jk
{
    WorldScene::WorldScene()
        : mPlayer(nullptr)
    {
    }
    WorldScene::~WorldScene()
    {
        
        
    }
    void WorldScene::Initialize()
    {
        mPlayer = object::Instantiate<Hero>(enums::eLayerType::Player);
        //object::DontDestroyOnLoad(mPlayer);

        SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
        sr->SetSprite(Resources::Find<graphics::Texture>(L"Player"));
        
        
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
    void WorldScene::Render()
    {
        Scene::Render();
        //graphics::GetDevice()->Draw();
    }
    void WorldScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void WorldScene::OnExit()
    {
        Scene::OnExit();
    }
    
}
