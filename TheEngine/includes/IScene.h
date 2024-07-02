#pragma once
#include "Entity.h"
#include <vector>


class IScene
{
public:
    virtual ~IScene() = default;
    virtual void Load() = 0;
    virtual void Draw() = 0;

protected:
    Entity* m_Entity;

    std::vector<Entity*> m_EntityVector;
};