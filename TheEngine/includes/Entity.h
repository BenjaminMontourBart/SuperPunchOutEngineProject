#pragma once
#include "Component.h"
#include <vector>
#include <map>

class Entity
{
public:
	~Entity() = default;
	Entity(const char* name);
	const char* GetName() { return m_Name; }
	void Update(float dt);
	void Draw();
	template<typename T>T* AddComponent()
	{
		Component* cmp = new T();
		m_Components.emplace_back(cmp);
	}
private:

	std::map<const type_info*, Component*> m_Components;
	std::vector<IUpdatable*> m_Update;
	std::vector<IDrawable*> m_Draw;
	const char* m_Name;

};


//class Entity
//{
//public:
//	virtual ~Entity() = default;
//	virtual void Start() {}
//	virtual void Update(float dt) {}
//	virtual void Draw() {}
//	virtual void Destroy() {}
//	const char* GetName() { return m_name; }
//
//
//protected:
//	char* m_name;
//};