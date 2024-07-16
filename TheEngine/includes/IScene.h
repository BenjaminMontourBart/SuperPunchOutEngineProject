#pragma once
#include "Entity.h"
#include <vector>

namespace Homer
{
    class IScene
    {
    public:
        virtual ~IScene() = default;
        virtual void Load() = 0;

    protected:
        Entity* m_Entity;

        std::vector<Entity*> m_EntityVector;
    };
}