#include "Game.h"
#include "Windows.h"
#include "Engine.h"
#include "Color.h"
#include "Player.h"
#include "Mechant.h"
#include "Scene.h"
#include "FightScene.h"
#include <iostream>

using namespace Homer;


Game::Game()
{
}

Game::~Game()
{
	Engine::Get().Gfx().Clear();
}
void Game::Init(const std::string title, int w, int h)
{
	Engine::Get().World().Register("Scene", new Scene());
	Engine::Get().World().Register("SceneTest", new FightScene());
	Engine::Get().World().Load("Scene");
}

void Game::Update(float dt)
{

	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_P))
	{
		Engine::Get().Gfx().Clear();
		Engine::Get().World().Load("SceneTest");
	}


#ifdef DEBUG_MODE
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_ESCAPE))
	{
		Engine::Get().Exit();
	}
#endif

}

void Game::Render()
{
	Engine::Get().World().Draw();
	Engine::Get().Gfx().Present();
}
