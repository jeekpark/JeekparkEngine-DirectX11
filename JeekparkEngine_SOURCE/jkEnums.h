#pragma once


namespace jk::enums
{
    enum class eComponentType
    {
        Transform,
        SpriteRenderer,
        Animator,
        Script,
        Camera,
        End
    };
    enum class eLayerType
    {
        None,
        Backgorund,
        Player,
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
}