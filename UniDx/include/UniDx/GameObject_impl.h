#pragma once

#include "GameObject.h"
#include "Transform.h"


namespace UniDx
{

template<typename... ComponentPtrs>
GameObject::GameObject(const std::wstring& name, Vector3 position, ComponentPtrs&&... components) : GameObject(name)
{
    transform->position = position;
    Add(std::forward<ComponentPtrs>(components)...);
}

template<typename Predicate>
GameObject* GameObject::Find(Predicate pred) const
{
    for (auto& childPtr : transform->getChildGameObjects()) {
        if (pred(childPtr.get()))
            return childPtr.get();
    }
    for (auto& childPtr : transform->getChildGameObjects()) {
        GameObject* p = childPtr->Find(pred);
        if (p != nullptr) return p;
    }
    return nullptr;
}

} // namespace UniDx
