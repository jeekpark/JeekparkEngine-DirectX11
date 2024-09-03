#pragma once

#include "..\JeekparkEngine_SOURCE\jkSceneManager.h"
#include "jkTitleScene.h"
#include "jkPlayScene.h"
#include "jkToolScene.h"
#include "jkWorldScene.h"
#include "jkLoadingScene.h"
namespace jk
{

    void LoadScenes()
    {
        SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
        SceneManager::CreateScene<TitleScene>(L"TitleScene");
        SceneManager::CreateScene<WorldScene>(L"WorldScene");

        SceneManager::LoadScene(L"LoadingScene");
    }
}