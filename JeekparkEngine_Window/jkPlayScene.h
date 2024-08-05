#pragma once

#include "..\JeekparkEngine_SOURCE\jkScene.h"


namespace jk
{

    class PlayScene : public Scene
    {
    public:
        PlayScene();
        ~PlayScene();
        
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;
    private:

    };

}

