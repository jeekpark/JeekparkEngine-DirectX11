#include "jkRenderer.h"

#include "jkGraphicDevice_DX11.h"
#include "jkResources.h"
#include "jkShader.h"

namespace jk::renderer
{
    Camera* mainCamera = nullptr;

	std::vector<graphics::Vertex> vertexes = {};
	std::vector<UINT> indices;

	graphics::VertexBuffer vertexBuffer;
	ID3D11Buffer* indexBuffer = nullptr;
	ID3D11Buffer* constantBuffer = nullptr;

	ID3D11InputLayout* inputLayouts = nullptr;

	static void LoadTriangleMesh()
	{
		renderer::vertexes.resize(3);
		renderer::vertexes[0].pos = Vector3(0.f, 0.5f, 0.0f);
		renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		renderer::vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		renderer::vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);



		/*indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);*/

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

	}
	static void LoadMesh()
	{
        LoadTriangleMesh();
	}

	static void LoadShaders()
	{
		jk::Resources::Load<graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");

	}

	void Initialize()
    {
        LoadMesh();
		LoadShaders();
	}
	void Release()
	{
		inputLayouts->Release();
		indexBuffer->Release();
		constantBuffer->Release();
	}
}

