#pragma once
#include <string>
#include <vector>
#include "ISound.h"
#include "Entity.h"

class Game
{
public:

	Game();
	~Game();
	void Init(const std::string title, int w, int h);
	void Update(float dt);
	void Render();

private:
	Entity* m_Entity;

	std::vector<Entity*> m_EntityVector;
};
