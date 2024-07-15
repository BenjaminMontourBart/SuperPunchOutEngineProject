#include "Entity.h"

Homer::Entity::~Entity()
{
	for (auto& i : m_Components)
	{
		delete i.second;
	}
}

Homer::Entity::Entity(const char* name)
	:m_Name(name)
{
}

void Homer::Entity::Update(float dt)
{
	for (auto& i : m_Update)
	{
		i->Update(dt);
	}
}

void Homer::Entity::Draw()
{
	for (auto& i : m_Draw)
	{
		i->Draw();
	}
}
