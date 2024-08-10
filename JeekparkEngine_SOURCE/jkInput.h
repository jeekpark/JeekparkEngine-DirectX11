#pragma once

#include "CommonInclude.h"

namespace jk
{
    enum class eKeyState
    {
        Down,
        Pressed,
        Up,
        None,
    };

    enum class eKeyCode
    {
        Q, W, E, R, T, Y, U, I, O, P,
        A, S, D, F, G, H, J, K, L,
        Z, X, C, V, B, N, M,
        Left, Right, Down, Up,
        LButton, MButton, RButton,
        End,
    };

    class Input
    {
    public:
        struct Key
        {
            eKeyCode keyCode;
            eKeyState state;
            bool bPressed;
        };

        static void Initialize();
        static void Update();

        static bool GetKeyDown(eKeyCode code) { return mKeys[(size_t)code].state == eKeyState::Down; }
        static bool GetKeyUp(eKeyCode code) { return mKeys[(size_t)code].state == eKeyState::Up; }
        static bool GetKey(eKeyCode code) { return mKeys[(size_t)code].state == eKeyState::Pressed; }
        static math::Vector2 GetMousePostion() { return mMousePostion; }
    private:
        static std::vector<Key> mKeys;
        static math::Vector2 mMousePostion;
    };
}

