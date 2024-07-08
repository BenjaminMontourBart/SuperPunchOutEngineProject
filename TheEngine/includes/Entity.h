#pragma once
#include "IDrawable.h"
#include "IUpdatable.h"
#include <vector>
#include <map>

class Component;

class Entity
{
public:
	~Entity();
	Entity(const char* name);
	const char* GetName() { return m_Name; }
	void Update(float dt);
	void Draw();
	template<typename T>T* AddComponent()
	{
		T* cmp = new T();
		const type_info* type = &typeid(*cmp);
		m_Components.emplace(type, cmp);
		IUpdatable* update = dynamic_cast<IUpdatable*>(cmp);
		if (update != nullptr)
		{
			m_Update.push_back(update);
		}
		IDrawable* draw = dynamic_cast<IDrawable*>(cmp);
		if (draw != nullptr)
		{
			m_Draw.push_back(draw);
		}
		return cmp;
	}
	template<typename T>T* GetComponent()
	{
		const type_info* type = &typeid(T);
		return m_Components.at(type);
	}


private:

	std::map<const type_info*, Component*> m_Components;
	std::vector<IUpdatable*> m_Update;
	std::vector<IDrawable*> m_Draw;

	const char* m_Name;

};
