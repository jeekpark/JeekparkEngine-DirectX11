#pragma once

#include "jkResource.h"

namespace jk
{
    class Resources
    {
    public:
        template <typename T>
        static T* Find(const std::wstring& key)
        {
            auto iter = mResources.find(key);
            if (iter == mResources.end())
            {
                return nullptr;
            }
            else
            {
                return dynamic_cast<T*>(iter->second);
            }
        }

        template <typename T>
        static T* Load(const std::wstring& key, const std::wstring& path)
        {
            T* resource = Resources::Find<T>(key);
            if (resource != nullptr)
            {
                return resource;
            }
            
            resource = new T();
            resource->Load(path);
            resource->SetName(key);
            resource->SetPath(path);
            mResources.insert(std::make_pair(key, resource));

            return resource;
        }

        static void Release()
        {
            for (auto& iter : mResources)
            {
                delete iter.second;
                iter.second = nullptr;
            }
        }
    private:
        static std::map<std::wstring, Resource*> mResources;

    };

}