#include "jkAudioClip.h"


namespace jk
{
    AudioClip::AudioClip()
        : Resource(enums::eResourceType::AudioClip)
        , mChannel(nullptr)
        , mSound(nullptr)
    {

    }
    AudioClip::~AudioClip()
    {
    }
    HRESULT AudioClip::Load(const std::wstring& path)
    {
        std::string cPath(path.begin(), path.end());
        if (!Fmod::CreateSound(cPath, mSound))
        {
            return E_FAIL;
        }
        return E_NOTIMPL;
    }
}