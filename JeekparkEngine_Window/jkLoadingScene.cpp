#include "jkLoadingScene.h"

#include "jkSceneManager.h"
#include "jkResources.h"
#include "jkTexture.h"
#include "jkApplication.h"
#include "jkRenderer.h"
#include "jkSceneManager.h"
#include "jkWorldScene.h"
#include "jkTitleScene.h"
extern jk::Application app;

namespace jk
{
    LoadingScene::LoadingScene()
        : mbLoadCompleted(false)
        , mResourcesLoadThread()
        , mMutexExclusion()
    {
    }
    LoadingScene::~LoadingScene()
    {
        delete mResourcesLoadThread;
        mResourcesLoadThread = nullptr;
    }
    void LoadingScene::Initialize()
    {
        mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutexExclusion));
    }
    void LoadingScene::Update()
    {
    }
    void LoadingScene::LateUpdate()
    {
    }
    void LoadingScene::Render()
    {
        if (mbLoadCompleted)
        {
            mResourcesLoadThread->join();
            SceneManager::LoadScene(L"WorldScene");
        }
    }
    void LoadingScene::OnEnter()
    {
    }
    void LoadingScene::OnExit()
    {
    }
    void LoadingScene::resourcesLoad(std::mutex& m)
    {
        while (true)
        {
            if (app.IsLoaded() == true)
            {
                break;
            }
        }

        m.lock();
        {
            Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\CloudOcean.png");
            renderer::Initialize();
            SceneManager::CreateScene<TitleScene>(L"TitleScene");
            SceneManager::CreateScene<WorldScene>(L"WorldScene");
            
        }
        m.unlock();

        mbLoadCompleted = true;
    }
}
