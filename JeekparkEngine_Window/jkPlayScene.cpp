#include "jkPlayScene.h"

#include "jkGameObject.h"
#include "jkSpriteRenderer.h"
#include "jkTransform.h"
#include "jkPlayer.h"
#include "jkInput.h"
#include "jkTitleScene.h"
#include "jkSceneManager.h"
#include "jkObject.h"
#include "jkTexture.h"
#include "jkResources.h"

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
        

        bg = object::Instantiate<Player>(
            enums::eLayerType::Backgorund,
            math::Vector2(0, 0)
        );
        SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
        graphics::Texture* texture = Resources::Find<graphics::Texture>(L"BG");
        sr->SetTexture(texture);
        //sr->SetSize(math::Vector2(3, 3));

        Scene::Initialize();

    }
    void PlayScene::Update()
    {
        Scene::Update();
    }
    void PlayScene::LateUpdate()
    {
        Scene::LateUpdate();
        if (Input::GetKeyDown(eKeyCode::N))
        {
            SceneManager::LoadScene(L"TitleScene");
        }
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
        wchar_t str[50] = L"Play Scene";
        TextOut(hdc, 0, 0, str, (int)wcsnlen_s(str, 50));
    }
    void PlayScene::OnEnter()
    {
    }
    void PlayScene::OnExit()
    {
    }
}
