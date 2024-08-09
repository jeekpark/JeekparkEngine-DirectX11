#pragma once

#include "CommonInclude.h"

using namespace jk::math;

namespace jk
{
    class Entity
    {
    public:
        Entity();
        virtual ~Entity();

        void SetName(const std::wstring& name) { mName = name; }
        const std::wstring& GetName() { return mName; }
    private:
        std::wstring mName;
    };

}