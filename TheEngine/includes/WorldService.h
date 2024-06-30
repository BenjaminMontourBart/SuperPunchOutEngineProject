#pragma once
#include "IWorld.h"
#include <string>
#include <vector>
#include <map>


class WorldService : public IWorld
{
    ~WorldService();
    virtual void Add(Entity* entity) override;
    virtual Entity* Find(std::string name) override;
    virtual void Remove(Entity* entity) override;
    virtual void Load(const char* scene) override;
    virtual void Register(const char* name, IScene* scene) override;
    void Update(float dt);
    void Draw();

    private:
    std::vector<Entity*> m_EntitiesInWorld = std::vector<Entity*>();
    std::map<const char*, Entity*> m_EntitiesDict;

    std::map<std::string, IScene*> m_Scenes;
    IScene* m_CurrentScene = nullptr;
};