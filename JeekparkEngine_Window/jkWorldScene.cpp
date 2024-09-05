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
        graphics::GetDevice()->Draw();
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
