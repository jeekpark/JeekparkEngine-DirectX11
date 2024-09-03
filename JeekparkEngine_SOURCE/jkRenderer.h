#pragma once

#include "jkCamera.h"
#include "jkGraphicDevice_DX11.h"

#include "jkMesh.h"

#include "jkConstantBuffer.h"

using namespace jk::math;
using namespace jk::graphics;

namespace jk::renderer
{
    extern Camera* mainCamera;

    extern std::vector<graphics::Vertex> vertexes;
    extern std::vector<UINT> indices;

    extern Mesh* mesh;
    extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

    extern ID3D11Buffer* constantBuffer;

    extern ID3D11InputLayout* inputLayouts;

    void Initialize();
    void Release();
}

