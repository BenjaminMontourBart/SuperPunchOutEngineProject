#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Mechant.h"

using namespace Homer;

Scene::~Scene()
{

}

void Scene::Load()
{
	m_EntityVector.clear();
	Entity* player = Engine::Get().World().Create("Player");
	Player* ne = player->AddComponent<Player>();
	ne->Start(300, 300, 200, 200);
	/*m_Entity = new Player(300, 300, 200, 200, "Player");
	m_EntityVector.push_back(m_Entity);
	m_Entity = new Mechant(100, 100, 100, 100, "Enemy");
	m_EntityVector.push_back(m_Entity);*/

	//for (int i = 0; i < m_EntityVector.size(); i++)
	//{
	//	Engine::Get().World().Add(m_EntityVector[i]);
	//	//m_EntityVector[i]->Start();
	//}

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void Scene::Draw()
{
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/oopsi.jpg");
	Engine::Get().Gfx().DrawTexture(_Btexture, Red);
}
