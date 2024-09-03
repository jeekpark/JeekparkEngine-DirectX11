#include "jkSceneManager.h"

#include "jkDontDestroyOnLoad.h"
namespace jk
{
    std::map<std::wstring, Scene*> SceneManager::sScene = {};
    Scene* SceneManager::sActiveScene = nullptr;
    Scene* SceneManager::sDontDestroyOnLoad = nullptr;

    std::vector<GameObject*> SceneManager::GetGameObjects(enums::eLayerType layer)
    {
        std::vector<GameObject*> gameObjects
            = sActiveScene->GetLayer(layer)->GetGameObjects();
        std::vector<GameObject*> dontDestroyOnLoad
            = sDontDestroyOnLoad->GetLayer(layer)->GetGameObjects();

        gameObjects.insert(gameObjects.end()
            , dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());

        return gameObjects;
    }

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
    void SceneManager::Render()
    {
        sActiveScene->Render();
        sDontDestroyOnLoad->Render();
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