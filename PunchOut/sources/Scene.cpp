#include "Scene.h"
#include "Engine.h"
#include "Animation.h"


using namespace Homer;

Scene::~Scene()
{

}

void Scene::Load()
{

	m_EntityVector.clear();

	entity.push_back(Engine::Get().World().Create("BackGround"));

	Animation* anim = entity[0]->AddComponent<Animation>();
	anim->SetPos(0, 0, 800, 600);
	anim->Init(1, 432, 176);
	anim->Load("assets/StartSheet.png");
	anim->AddFrame("Ring1", 0, 0, 800, 600);
	anim->AddClip("BackGround", 0, 1, 0.3f);

	anim->Play("BackGround", true);
	m_EntityVector.push_back(entity[0]);

	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/Menu.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void Scene::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_SPACE))
	{
		Engine::Get().Sound().StopMusic();
		Engine::Get().World().Load("SceneTest");
	}
}
