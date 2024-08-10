#pragma once

#include "..\JeekparkEngine_SOURCE\jkGameObject.h"

namespace jk
{

    class Cat : public GameObject
    {
    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:
    };

}