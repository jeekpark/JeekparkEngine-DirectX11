#include "jkHero.h"

namespace jk
{
    Hero::Hero()
    {
    }
    Hero::~Hero()
    {
    }
    void Hero::Initialize()
    {
        GameObject::Initialize();
    }
    void Hero::Update()
    {
        GameObject::Update();
    }
    void Hero::LateUpdate()
    {
        GameObject::LateUpdate();
    }
    void Hero::Render()
    {
        GameObject::Render();
    }
}