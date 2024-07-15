#pragma once
#include "IWorld.h"
#include <string>
#include <vector>
#include <map>

namespace Homer
{
    class WorldService : public IWorld
    {
        ~WorldService();
        virtual void Add(Entity* entity) override;
        virtual Entity* Create(const char* name) override;
        virtual Entity* Find(std::string name) override;
        virtual void Remove(Entity* entity) override;
        virtual void Load(const char* scene) override;
        virtual void Register(const char* name, IScene* scene) override;
        virtual void Unload() override;
        virtual void Update(float dt) override;
        virtual void Draw() override;

    private:
        std::vector<Entity*> m_EntitiesInWorld = std::vector<Entity*>();
        std::map<const char*, Entity*> m_EntitiesDict;

        std::map<std::string, IScene*> m_Scenes;
        IScene* m_CurrentScene = nullptr;
    };
}