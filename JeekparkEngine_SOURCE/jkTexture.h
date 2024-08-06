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
        Texture();
        ~Texture();

        virtual HRESULT Load(const std::wstring& path) override;

        UINT GetWidth() { return mWidth; }
        UINT GetHeight() { return mHeight; }
        HDC GetHdc() { return mHdc; }
        eTextureType GetTextureType() { return mTextureType; }
        Gdiplus::Image* GetImage() { return mImage; }

    private:
        eTextureType mTextureType;
        Gdiplus::Image* mImage;
        HBITMAP mBitmap;
        HDC mHdc;

        UINT mWidth;
        UINT mHeight;
    };

}