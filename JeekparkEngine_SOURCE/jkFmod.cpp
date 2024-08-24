#include "jkFmod.h"

namespace jk
{
    FMOD::Studio::System* Fmod::mSystem = nullptr;
    FMOD::System* Fmod::mCoreSystem = nullptr;

    void Fmod::Initialize()
    {
        void* extraDriverData = nullptr;

        FMOD::Studio::System::create(&mSystem);
        mSystem->getCoreSystem(&mCoreSystem);
        mCoreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);
    }
    bool Fmod::CreateSound(const std::string& path, FMOD::Sound* sound)
    {
        if (FMOD_OK != mCoreSystem->createSound(path.c_str(), FMOD_3D, 0, &sound))
        {
            return false;
        }

        return false;
    }
    void Fmod::SoundPlay(FMOD::Sound* sound, FMOD::Channel* channel)
    {
    }
}