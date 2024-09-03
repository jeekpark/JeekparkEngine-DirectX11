#pragma once

#include "jkResource.h"

namespace jk::graphics
{

    class Texture : public Resource
    {
    public:
        enum class eTextureType
        {
            Bmp,
            Png,
            None,
        };

        static Texture* Create(const std::wstring& name, UINT width, UINT height);

        Texture();
        ~Texture();

        virtual HRESULT Save(const std::wstring& path) override;
        virtual HRESULT Load(const std::wstring& path) override;

        UINT GetWidth() const { return mWidth; }
        void SetWidth(UINT width) { mWidth = width; }
        UINT GetHeight() const { return mHeight; }
        void SetHeight(UINT height) { mHeight = height; }

    private:
        bool mbAlpha;
        eTextureType mTextureType;

        UINT mWidth;
        UINT mHeight;
    };

}