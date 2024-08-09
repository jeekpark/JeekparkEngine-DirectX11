#pragma once

#include "jkComponent.h"

namespace jk
{

    class Script : public Component
    {
    public:
        Script();
        ~Script();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;
    private:


    };

}