#include "BackGround.h"
#include "Engine.h"

void Homer::BackGround::Start()
{
	//Engine::Get().animation().Init(1, 432, 176);
	//Engine::Get().atlas().Load("assets/Ring.png");
	//Engine::Get().atlas().AddFrame("Ring1", 0, 0, 432, 176);
	//Engine::Get().atlas().AddFrame("Ring2", 0, 256, 432, 176);
	//Engine::Get().atlas().AddFrame("Ring3", 0, 512, 432, 176);
	//Engine::Get().atlas().AddFrame("Ring4", 0, 768, 432, 176);
	//Engine::Get().animation().AddClip("BackGround", 0, 3, 1);

	//Engine::Get().animation().Play("BackGround", true);
}

void Homer::BackGround::Update(float dt)
{
	//Engine::Get().animation().Update(dt);
}

void Homer::BackGround::LoadTexture(const std::string filename)
{
}

void Homer::BackGround::Draw()
{
	//Engine::Get().atlas().Draw();
}
