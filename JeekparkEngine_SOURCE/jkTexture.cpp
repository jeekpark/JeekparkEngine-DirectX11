#include "jkTexture.h"

#include "jkApplication.h"
#include "jkResources.h"

extern jk::Application app;

namespace jk::graphics
{
    Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
    {
        Texture* image = Resources::Find<Texture>(name);
        if (image)
        {
            return image;
        }

        image = new Texture();
        image->SetName(name);
        image->SetWidth(width);
        image->SetHeight(height);

        HDC hdc = app.GetHdc();
        HWND hwnd = app.GetHwnd();

        image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
        image->mHdc = CreateCompatibleDC(hdc);

        HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
        DeleteObject(oldBitmap);

        Resources::Insert(name, image);

        return image;
    }

    Texture::Texture()
        : Resource(enums::eResourceType::Texture)
        , mbAlpha(false)
    {
    }
    Texture::~Texture()
    {
    }
    HRESULT Texture::Load(const std::wstring& path)
    {
        std::wstring ext = path.substr(path.find_last_of(L".") + 1);

        if (ext == L"bmp")
        {
            mTextureType = eTextureType::Bmp;
            mBitmap = (HBITMAP)LoadImageW(
                nullptr,
                path.c_str(),
                IMAGE_BITMAP,
                0,
                0,
                LR_LOADFROMFILE | LR_CREATEDIBSECTION
            );
            assert(mBitmap != nullptr);
            BITMAP info = {};
            GetObject(mBitmap, sizeof(BITMAP), &info);

            mWidth = info.bmWidth;
            mHeight = info.bmHeight;

            if (info.bmBitsPixel == (WORD)32)
            {
                mbAlpha = true;
            }
            else if (info.bmBitsPixel == (WORD)24)
            {
                mbAlpha = false;
            }

            HDC mainDC = app.GetHdc();
            mHdc = CreateCompatibleDC(mainDC);

            HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
            DeleteObject(oldBitmap);
        }
        else if (ext == L"png")
        {
            mTextureType = eTextureType::Png;
            mImage = Gdiplus::Image::FromFile(path.c_str());
            assert(mImage->GetLastStatus() == Gdiplus::Ok);
            mWidth = mImage->GetWidth();
            mHeight = mImage->GetHeight();
        }
        

        return S_OK;
    }
}