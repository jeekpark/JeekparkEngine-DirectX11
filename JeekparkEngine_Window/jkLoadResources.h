#pragma once

#include "..\JeekparkEngine_SOURCE\jkResources.h"
#include "..\JeekparkEngine_SOURCE\jkTexture.h"



namespace jk
{

    void LoadResources()
    {
        Resources::Load<graphics::Texture>(
            L"BG",
            L"C:\\Users\\9001\\Desktop\\CloudOcean.png"
        );
    }
}