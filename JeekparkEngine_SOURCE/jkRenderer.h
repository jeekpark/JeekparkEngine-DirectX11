#pragma once
#include "jkCamera.h"
#include "jkGraphicDevice_DX11.h"

#include "jkConstantBuffer.h"

using namespace jk::math;
using namespace jk::graphics;

namespace jk::renderer
{
    extern Camera* mainCamera;
    extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

    void Initialize();
    void Release();
}

