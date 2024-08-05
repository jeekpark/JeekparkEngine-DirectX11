#include "jkPlayScene.h"

#include "jkGameObject.h"

namespace jk
{
    PlayScene::PlayScene()
    {
    }
    PlayScene::~PlayScene()
    {
    }
    void PlayScene::Initialize()
    {
        for (size_t i = 0; i < 100; ++i)
        {
            GameObject* obj = new GameObject();
            obj->SetPosition(rand() % 1920, rand() % 1080);
            Scene::AddGameObject(obj);
        }
    }
    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
}
