#include "WorldService.h"

WorldService::~WorldService()
{
	if (m_EntitiesInWorld.size() > 0)
	{
		delete &m_EntitiesInWorld;
		m_EntitiesInWorld = std::vector<Entity*>();
	}
	if (m_EntitiesDict.size() > 0)
	{
		delete& m_EntitiesDict;
		m_EntitiesDict = std::map<const char*, Entity*>();
	}		
}

void WorldService::Add(Entity* entity)
{
	m_EntitiesInWorld.push_back(entity);
}
Entity* WorldService::Find(std::string name)
{
    /////adapter en dictionnaire
    for (int i = 0; i < m_EntitiesInWorld.size(); i++)
    {
        if (m_EntitiesInWorld[i]->GetName() == name)
        {
            return m_EntitiesInWorld[i];
        }
        return nullptr;
    }
}
void WorldService::Remove(Entity* entity)
{
	for (auto i = m_EntitiesDict.end(); i != m_EntitiesDict.begin(); i--)
	{
		(*i).second->GetName();
	}
}
void WorldService::Load(const char* scene)
{
}
void WorldService::Register(const char* name, IScene* scene)
{
}
void WorldService::Update(float dt)
{
	for (auto entity : m_EntitiesInWorld)
	{
		entity->Update(dt);
	}
}
void WorldService::Draw()
{
	for (auto entity : m_EntitiesInWorld)
	{
		entity->Draw();
	}
}