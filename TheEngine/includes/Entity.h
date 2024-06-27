#pragma once

class Entity
{
public:
	virtual ~Entity() = default;
	virtual void Start() {}
	virtual void Update(float dt) {}
	virtual void Draw() {}
	virtual void Destroy() {}
	const char* GetName() { return m_name; }


private:
	const char* m_name;
};