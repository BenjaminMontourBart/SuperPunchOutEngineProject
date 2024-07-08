#pragma once
#include "Entity.h"
#include "IScene.h"
#include <string>

class IWorld
{
public:
	virtual ~IWorld() = default;
	virtual void Add(Entity* entity) = 0;
	virtual Entity* Create(const char* name) = 0;
	virtual Entity* Find(std::string name) = 0;
	virtual void Remove(Entity* entity) = 0;
	virtual void Load(const char* scene) = 0;
	virtual void Register(const char* name, IScene* scene) = 0;
	virtual void Unload() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
};