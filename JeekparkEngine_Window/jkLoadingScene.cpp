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
            //���� ���ξ����尡 ����Ǵµ� �ڽľ����尡 �����ִٸ�
            //�ڽľ����带 ���ξ����忡 ���Խ��� ���ξ����尡 ����Ǳ������� block
            mResourcesLoadThread->join();

            //���ξ������ ���� �и� ���� �������� ������ �����
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
