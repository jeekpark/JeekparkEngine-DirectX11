#pragma once
#include "jkGraphicDevice_DX11.h"

namespace jk::graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

		UINT GetIndexCount() const { return mIndexCount; }
	private:
		UINT mIndexCount;
	};
}