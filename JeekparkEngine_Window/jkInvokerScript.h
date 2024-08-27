#pragma once

#include "..\JeekparkEngine_SOURCE\jkScript.h"

namespace jk
{
    class InvokerScript : public Script
    {
    public:
        enum class eState
        {
            Idle,
            StartRun,
            Run,
            EndRun,
            None,
        };

        InvokerScript();
        ~InvokerScript();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnCollisionEnter(class Collider* other) override;
        void OnCollisionStay(class Collider* other) override;
        void OnCollisionExit(class Collider* other) override;

        void AttackEffect();
    private:
        void idle();
        void startRun();
        void run();
        void endRun();


    private:
        eState mState;
        class Animator* mAnimator;
    };

}