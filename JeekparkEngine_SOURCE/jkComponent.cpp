#include "jkComponent.h"


namespace jk
{
    Component::Component(enums::eComponentType type)
        : mOwner(nullptr)
        , mComponentType(type)
    {
    }
    Component::~Component()
    {
    }
    void Component::Initialize()
    {
    }
    void Component::Update()
    {
    }
    void Component::LateUpdate()
    {
    }
    void Component::Render()
    {
    }
}