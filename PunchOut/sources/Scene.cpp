#include "Scene.h"
#include "Engine.h"


using namespace Homer;

Scene::~Scene()
{

}

void Scene::Load()
{
	m_EntityVector.clear();
	entity.push_back(Engine::Get().World().Create("Player"));
	player = entity[0]->AddComponent<Player>();
	player->Start(300, 300, 200, 200);
	m_EntityVector.push_back(entity[0]);

	entity.push_back(Engine::Get().World().Create("Enemy"));
	enemy = entity[1]->AddComponent<Mechant>();
	enemy->Start(100, 100, 100, 100);
	m_EntityVector.push_back(entity[1]);

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void Scene::Draw()
{
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/oopsi.jpg");
	Engine::Get().Gfx().DrawTexture(_Btexture, Red);
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().DrawString("Press P for change Scene", _Font, 200, 10, Red);
}
