#include "WorldService.h"

Homer::WorldService::~WorldService()
{
	Unload();
	for (auto i = m_Scenes.begin(); i != m_Scenes.end(); i++)
	{
		delete i->second;
	}
	m_Scenes.clear();
}

void Homer::WorldService::Add(Entity* entity)
{
	m_EntitiesInWorld.push_back(entity);
}
void Homer::WorldService::SetActive(const char* name)
{
	m_EntitiesInWorld.push_back(m_EntitiesDict[name]);
}
Homer::Entity* Homer::WorldService::Create(const char* name)
{
	Entity* _e = new Entity(name);
	Add(_e);
	return _e;
}
Homer::Entity* Homer::WorldService::Find(std::string name)
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
	return nullptr;
}
void Homer::WorldService::Remove(Entity* entity)
{
	auto it = std::find(m_EntitiesInWorld.begin(), m_EntitiesInWorld.end(),entity);

	if (it != m_EntitiesInWorld.end()) {
		m_EntitiesInWorld.erase(it);
	}


}
void Homer::WorldService::Load(const char* scene)
{
	if (m_CurrentScene != m_Scenes[scene])
	{
		Unload();

		if (m_Scenes.count(scene) > 0)
		{
			m_CurrentScene = m_Scenes[scene];
			m_Scenes[scene]->Load();
		}
	}
}
void Homer::WorldService::Register(const char* name, IScene* scene)
{
	if (m_Scenes.count(name) > 0)
	{
		Load(name);
	}
	else
	{
		m_Scenes.emplace(name, scene);
	}
}
void Homer::WorldService::Unload()
{
	if (m_CurrentScene != nullptr)
	{
		for (auto entity : m_EntitiesInWorld)
		{
			delete entity;
		}
		m_EntitiesInWorld.clear();
		m_EntitiesDict.clear();
	}
}

void Homer::WorldService::Update(float dt)
{
	for (auto entity : m_EntitiesInWorld)
	{
		entity->Update(dt);
	}
	m_CurrentScene->Update(dt);
}
void Homer::WorldService::Draw()
{
	for (auto entity : m_EntitiesInWorld)
	{
		entity->Draw();
	}
}