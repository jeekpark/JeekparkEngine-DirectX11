#pragma once

#include "..\JeekparkEngine_SOURCE\jkScript.h"

namespace jk
{
    class PlayerScript : public Script
    {
    public:
        PlayerScript();
        ~PlayerScript();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:

    };

}