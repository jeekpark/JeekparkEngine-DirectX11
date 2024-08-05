#pragma once

#include "..\JeekparkEngine_SOURCE\jkSceneManager.h"
#include "jkPlayScene.h"


namespace jk
{

    void LoadScenes()
    {
        SceneManager::CreateScene<PlayScene>(L"PlayScene");

        SceneManager::LoadScene(L"PlayScene");
    }
}