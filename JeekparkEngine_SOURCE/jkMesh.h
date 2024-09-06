#pragma once
#include "jkResource.h"
#include "jkInputLayout.h"
#include "jkVertexBuffer.h"
#include "jkIndexBuffer.h"


namespace jk
{
	class Mesh : public Resource
	{
	public:
		struct Data
		{
			Data();
			~Data();

			D3D11_PRIMITIVE_TOPOLOGY mTopology;
			std::vector<graphics::Vertex> vertices;
			std::vector<UINT> indices;
		};

		Mesh();
		~Mesh();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;


		bool CreateVB(const std::vector<graphics::Vertex>& vertices);
		bool CreateIB(const std::vector<UINT>& indices);
		void SetVertexBufferParams(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* ShaderBytecodeWithInputSignature, SIZE_T BytecodeLength);

		void Bind();

		UINT GetIndexCount() const { return mIB.GetIndexCount(); }
	private:
		graphics::InputLayout mInputLayout;
		graphics::VertexBuffer mVB;
		graphics::IndexBuffer mIB;

		Data mData;
	};
}