#include "Entity.h"

Entity::~Entity()
{
	for (auto& i : m_Components)
	{
		delete i.second;
	}
}

Entity::Entity(const char* name)
	:m_Name(name)
{
}

void Entity::Update(float dt)
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

void Entity::Draw()
{
	if (!m_Draw.empty())
	{
		for (auto& i : m_Draw)
		{
			//if (i->Draw())
			//{
				i->Draw();
			//}
			//else
			//{
			//	delete i;
			//}
		}
	}
}
