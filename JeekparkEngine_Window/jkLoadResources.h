#pragma once

#include "..\JeekparkEngine_SOURCE\jkResources.h"
#include "..\JeekparkEngine_SOURCE\jkTexture.h"



namespace jk
{
    void LoadResources()
    {
        Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\chickenAlpha.bmp");
        Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
        Resources::Load<graphics::Texture>(L"SakuyaTexture", L"..\\Resources\\SakuyaIzayoi.png");

    }
}