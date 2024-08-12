#pragma once

#include "..\JeekparkEngine_SOURCE\jkScript.h"

namespace jk
{
    class SakuyaScript : public Script
    {
    public:
        enum class eState
        {
            Idle,
            StartRun,
            Run,
            EndRun,
            SitDown,
            StopJump,
            RunJump,
            Float,
            Attack,
            None,
        };

        SakuyaScript();
        ~SakuyaScript();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void AttackEffect();
    private:
        void idle();
        void startRun();
        void run();
        void endRun();


    private:
        eState mState;
        enums::eDirection mDirection;
        class Animator* mAnimator;

    };

}