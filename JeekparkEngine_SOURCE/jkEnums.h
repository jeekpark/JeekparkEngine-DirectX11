#pragma once


namespace jk::enums
{
    enum class eComponentType
    {
        Transform,
        Collider,
        Script,
        SpriteRenderer,
        Animator,
        Camera,
        End
    };
    enum class eLayerType
    {
        None,
        Backgorund,
        Animal,
        Player,
        Particle,
        Max,
    };

    enum class eResourceType
    {
        Texture,
        AudioClip,
        Animation,
        Prefab,
        End,
    };

    enum class eDirection
    {
        Left,
        Right,
        Up,
        Down,
        None,
    };
}