#include "FightScene.h"
#include "Engine.h"

using namespace Homer;

FightScene::~FightScene()
{
	
}

void FightScene::Load()
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


	///////////// in entity backGround
	Engine::Get().animation().Init(1, 432, 176);
	Engine::Get().atlas().Load("assets/Ring.png");
	Engine::Get().atlas().AddFrame("Ring1", 0, 0, 432, 176);
	Engine::Get().atlas().AddFrame("Ring2", 0, 256, 432, 176);
	Engine::Get().atlas().AddFrame("Ring3", 0, 512, 432, 176);
	Engine::Get().atlas().AddFrame("Ring4", 0, 768, 432, 176);
	Engine::Get().animation().AddClip("BackGround", 0, 3, 1);

	Engine::Get().animation().Play("BackGround", true);
}

void FightScene::Draw()
{
	//Engine::Get().atlas().Draw();
	//size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/Ring.png");

	//Engine::Get().Gfx().DrawTexture(_Btexture, Red);
}
