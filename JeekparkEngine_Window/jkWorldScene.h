#pragma once

#include "..\JeekparkEngine_SOURCE\jkScene.h"

namespace jk
{
    class WorldScene : public Scene
    {
    public:
        WorldScene();
        ~WorldScene();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void OnEnter() override;
        void OnExit() override;
    private:

        void initCamera();
        void initPlayableHero();
    };

}
