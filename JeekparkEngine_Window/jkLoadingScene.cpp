#include "jkLoadingScene.h"

#include "jkSceneManager.h"
#include "jkResources.h"
#include "jkTexture.h"
namespace jk
{
    LoadingScene::LoadingScene()
        : mbLoadCompleted(false)
        , mResourcesLoadThread(nullptr)
        , mMutexExclusion()
    {
    }
    LoadingScene::~LoadingScene()
    {
        if (mResourcesLoadThread != nullptr)
        {
            delete mResourcesLoadThread;
            mResourcesLoadThread = nullptr;
        }
    }
    void LoadingScene::Initialize()
    {
        mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutexExclusion));
    }
    void LoadingScene::Update()
    {
        if (mbLoadCompleted)
        {
            //만약 메인쓰레드가 종료되는데 자식쓰레드가 남아있다면
            //자식쓰레드를 메인쓰레드에 편입시켜 메인쓰레드가 종료되기전까지 block
            mResourcesLoadThread->join();

            //메인쓰레드와 완전 분리 시켜 독립적인 쓰레드 운영가능
            //mResourcesLoad->detach();

            SceneManager::LoadScene(L"WorldScene");
        }
    }
    void LoadingScene::LateUpdate()
    {
    }
    void LoadingScene::Render(HDC hdc)
    {
    }
    void LoadingScene::OnEnter()
    {
    }
    void LoadingScene::OnExit()
    {
    }
    void LoadingScene::resourcesLoad(std::mutex& m)
    {
        m.lock();
        {
            Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
            Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
            Resources::Load<graphics::Texture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
            mbLoadCompleted = true;
        }
        m.unlock();
        
    }
}
