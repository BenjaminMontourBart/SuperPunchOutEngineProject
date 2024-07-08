#include "SceneTest.h"
#include "Engine.h"
#include "Player.h"
#include "Mechant.h"

using namespace Homer;

SceneTest::~SceneTest()
{
}

void SceneTest::Load()
{
	m_EntityVector.clear();

	//m_Entity = new Player(600, 300, 200, 200, "Player");
	//m_EntityVector.push_back(m_Entity);
	//m_Entity = new Mechant(200, 200, 100, 100, "Enemy");
	//m_EntityVector.push_back(m_Entity);

	//for (int i = 0; i < m_EntityVector.size(); i++)
	//{
	//	Engine::Get().World().Add(m_EntityVector[i]);
	//	//m_EntityVector[i]->Start();
	//}

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void SceneTest::Draw()
{
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/Harambe.png");
	Engine::Get().Gfx().DrawTexture(_Btexture, Red);
}
