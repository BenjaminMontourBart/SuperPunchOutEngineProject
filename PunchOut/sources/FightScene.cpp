#include "FightScene.h"
#include "Engine.h"
#include "Animation.h"

using namespace Homer;

FightScene::~FightScene()
{
	
}

void FightScene::Load()
{

	m_EntityVector.clear();

	entity.push_back(Engine::Get().World().Create("BackGround"));

	Animation* anim = entity[0]->AddComponent<Animation>();
	anim->SetPos(0, 0, 800, 600);
	anim->Init(1, 432, 176);
	anim->Load("assets/Ring.png");
	anim->AddFrame("Ring1", 0, 0, 432, 175);
	anim->AddFrame("Ring2", 0, 256, 432, 175);
	anim->AddFrame("Ring3", 0, 512, 432, 175);
	anim->AddFrame("Ring4", 0, 768, 432, 175);
	anim->AddClip("BackGround", 0, 3, 0.3f);

	anim->Play("BackGround", true);
	m_EntityVector.push_back(entity[0]);

	entity.push_back(Engine::Get().World().Create("Enemy"));
	enemy = entity[1]->AddComponent<Mechant>();
	enemy->Start(350, 200, 100, 100);
	m_EntityVector.push_back(entity[1]);

	entity.push_back(Engine::Get().World().Create("Player"));
	player = entity[2]->AddComponent<Player>();
	//player->Position.AddListener(enemy);
	player->Start(350, 320, 200, 200);
	m_EntityVector.push_back(entity[2]);

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/Tutorial.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);

}

void Homer::FightScene::Update(float dt)
{
}
