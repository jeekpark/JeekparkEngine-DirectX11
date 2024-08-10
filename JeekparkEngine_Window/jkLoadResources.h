#pragma once

#include "..\JeekparkEngine_SOURCE\jkResources.h"
#include "..\JeekparkEngine_SOURCE\jkTexture.h"



namespace jk
{
    void LoadResources()
    {
        Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
        Resources::Load<graphics::Texture>(L"PacMan", L"..\\Resources\\img\\pacman\\0.png");
        Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\chickenAlpha.bmp");
        Resources::Load<graphics::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
        Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");
    }
}