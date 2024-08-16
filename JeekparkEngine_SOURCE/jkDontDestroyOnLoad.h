#pragma once

#include "jkEntity.h"
#include "jkGameObject.h"
#include "jkLayer.h"
#include "jkScene.h"

namespace jk
{

    class DontDestroyOnLoad : public Scene
    {
    public:
        DontDestroyOnLoad();
        ~DontDestroyOnLoad();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;
    private:

    };

}

