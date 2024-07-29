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
		if (i != nullptr)
		{
			i->Update(dt);
		}
		else
		{
			delete i;
		}
	}
}

void Homer::Entity::Draw()
{
	if (!m_Draw.empty())
	{
		for (auto& i : m_Draw)
		{
			i->Draw();
		}
	}
}
