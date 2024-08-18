#pragma once

#include "..\JeekparkEngine_SOURCE\jkSceneManager.h"
#include "jkTitleScene.h"
#include "jkPlayScene.h"
#include "jkToolScene.h"

namespace jk
{

    void LoadScenes()
    {
        SceneManager::CreateScene<TitleScene>(L"TitleScene");
        SceneManager::CreateScene<PlayScene>(L"PlayScene");
        //SceneManager::CreateScene<ToolScene>(L"ToolScene");
        //SceneManager::LoadScene(L"TitleScene");
        SceneManager::LoadScene(L"PlayScene");
    }
}