#include "Entity.h"

Entity::Entity(const char* name)
	:m_Name(name)
{
}

void Entity::Update(float dt)
{
	for (auto& i : m_Update)
	{
		i->Update(dt);
	}
}

void Entity::Draw()
{
	for (auto& i : m_Draw)
	{
		i->Draw();
	}
}
