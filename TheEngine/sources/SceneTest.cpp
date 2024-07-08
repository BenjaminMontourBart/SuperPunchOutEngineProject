#include "SceneTest.h"
#include "Engine.h"

using namespace Homer;

SceneTest::~SceneTest()
{
	/*if (m_EntityVector.size() != 0)
	{
		m_EntityVector.clear();
	}
	if (entity.size() != 0)
	{
		entity.clear();
	}
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
	if (enemy != nullptr)
	{
		delete enemy;
		enemy = nullptr;
	}
	if (m_Entity != nullptr)
	{
		delete m_Entity;
		m_Entity = nullptr;
	}*/
	
}

void SceneTest::Load()
{
	m_EntityVector.clear();
	entity.push_back(Engine::Get().World().Create("Player"));
	player = entity[0]->AddComponent<Player>();
	player->Start(500, 200, 200, 200);
	m_EntityVector.push_back(entity[0]);

	entity.push_back(Engine::Get().World().Create("Enemy"));
	enemy = entity[1]->AddComponent<Mechant>();
	enemy->Start(100, 300, 100, 100);
	m_EntityVector.push_back(entity[1]);

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void SceneTest::Draw()
{
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/Harambe.png");
	Engine::Get().Gfx().DrawTexture(_Btexture, Red);
}
