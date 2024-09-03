#pragma once

#include "jkScene.h"


namespace jk
{
    class SceneManager
    {
    public:
        template <typename T>
        static Scene* CreateScene(const std::wstring& name)
        {
            T* scene = new T();
            scene->SetName(name);
            sActiveScene = scene;
            scene->Initialize();
            sScene.insert(std::make_pair(name, scene));
            return scene;
        }

        static Scene* LoadScene(const std::wstring& name);
        static Scene* GetActiveScene() { return sActiveScene; }
        static Scene* GetDontDestroyOnLoad() { return sDontDestroyOnLoad; }
        static std::vector<GameObject*> GetGameObjects(enums::eLayerType layer);
        static void Initialize();
        static void Update();
        static void LateUpdate();
        static void Render();
        static void Destroy();
        static void Release();
    private:
        static std::map<std::wstring, Scene*> sScene;
        static Scene* sActiveScene;
        static Scene* sDontDestroyOnLoad;
    };
}

