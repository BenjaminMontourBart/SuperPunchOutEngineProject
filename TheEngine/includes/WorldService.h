#pragma once
#include "IWorld.h"
#include <string>
#include <vector>
#include <map>


class WorldService : public IWorld
{
    virtual void Add(Entity* entity) override;
    virtual Entity* Find(std::string name) override;
    virtual void Remove(Entity* entity) override;
    void Update(float dt);
    void Draw();

    private:
    std::vector<Entity*> m_EntitiesInWorld = std::vector<Entity*>();
    std::map<const char*, Entity*> m_EntitiesDict;
};