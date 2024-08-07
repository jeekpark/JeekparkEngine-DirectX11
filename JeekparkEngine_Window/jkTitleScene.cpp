#include "jkTitleScene.h"

#include "jkInput.h"
#include "jkTitleScene.h"
#include "jkSceneManager.h"

namespace jk
{
    TitleScene::TitleScene()
    {
    }
    TitleScene::~TitleScene()
    {
    }
    void TitleScene::Initialize()
    {
        Scene::Initialize();
    }
    void TitleScene::Update()
    {
        Scene::Update();
    }
    void TitleScene::LateUpdate()
    { 
        Scene::LateUpdate();
        if (Input::GetKeyDown(eKeyCode::N))
        {
            SceneManager::LoadScene(L"PlayScene");
        }
    }
    void TitleScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
        wchar_t str[50] = L"Title Scene";
        TextOut(hdc, 0, 0, str, (int)wcsnlen_s(str, 50));
    }
}