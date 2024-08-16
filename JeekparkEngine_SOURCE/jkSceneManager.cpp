#include "jkSceneManager.h"

#include "jkDontDestroyOnLoad.h"
namespace jk
{
    std::map<std::wstring, Scene*> SceneManager::sScene = {};
    Scene* SceneManager::sActiveScene = nullptr;
    Scene* SceneManager::sDontDestroyOnLoad = nullptr;

    void SceneManager::Initialize()
    {
        sDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");

    }
    void SceneManager::Update()
    {
        sActiveScene->Update();
        sDontDestroyOnLoad->Update();
    }
    void SceneManager::LateUpdate()
    {
        sActiveScene->LateUpdate();
        sDontDestroyOnLoad->LateUpdate();
    }
    void SceneManager::Render(HDC hdc)
    {
        sActiveScene->Render(hdc);
        sDontDestroyOnLoad->Render(hdc);
    }
    void SceneManager::Destroy()
    {
        sActiveScene->Destroy();
        sDontDestroyOnLoad->Destroy();
    }
    Scene* SceneManager::LoadScene(const std::wstring& name)
    {
        if (sActiveScene)
        {
            sActiveScene->OnExit();
        }
        auto iter = sScene.find(name);

        if (iter == sScene.end())
        {
            return nullptr;
        }

        sActiveScene = iter->second;
        sActiveScene->OnEnter();
        return iter->second;
    }

    void SceneManager::Release()
    {
        for (auto& iter : sScene)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }
}