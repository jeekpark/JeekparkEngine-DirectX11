#pragma once

#include "..\JeekparkEngine_SOURCE\jkScript.h"

namespace jk
{
    class CatScript : public Script
    {
    public:
        enum class eState
        {
            SitDown,
            Walk,
            Sleep,
            LayDown,
            Attack,
        };

        enum class eDirection
        {
            Left,
            Right,
            Down,
            Up
        };

        CatScript();
        ~CatScript();

        void Initialize()override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetPlayer(GameObject* player) { mPlayer = player; }

        Vector2 mDest;
    private:
        void sitDown();
        void move();
        void layDown();
        void playWalkAnimationBydirection(eDirection dir);
        void translate(class Transform* tr);


    private:
        eState mState;
        class Animator* mAnimator;
        float mTime;
        eDirection mDirection;
        float mDeathTime;
        GameObject* mPlayer;
        float mRadian;
    };

}