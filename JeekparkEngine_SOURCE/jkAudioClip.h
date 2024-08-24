#pragma once

#include "jkFmod.h"
#include "jkResource.h"

namespace jk
{
    class AudioClip : public Resource
    {
    public:
        AudioClip();
        virtual ~AudioClip();

        HRESULT Load(const std::wstring& path) override;
    private:
        FMOD::Sound* mSound;
        FMOD::Channel* mChannel;
    };

}
