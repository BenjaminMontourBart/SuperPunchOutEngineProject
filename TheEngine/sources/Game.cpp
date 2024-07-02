#include "Game.h"
#include "Windows.h"
#include "Engine.h"
#include "Color.h"
#include "Player.h"
#include "Mechant.h"
#include "Scene.h"
#include "SceneTest.h"
#include <iostream>

using namespace Homer;


Game::Game()
{
}

Game::~Game()
{

}
void Game::Init(const std::string title, int w, int h)
{
	Engine::Get().Exit(true);

	Engine::Get().World().Register("Scene", new Scene());
	Engine::Get().World().Load("Scene");
}

void Game::Update(float dt)
{
	Engine::Get().World().Update(dt);

	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_P))
	{
		Engine::Get().World().Register("SceneTest", new SceneTest());
		Engine::Get().World().Load("SceneTest");
		std::cout << "allo" << std::endl;
	}


#ifdef DEBUG_MODE
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_ESCAPE))
	{
		Engine::Get().Exit(false);
	}
#endif


}

void Game::Render()
{

	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().Clear();
	Engine::Get().Gfx().DrawString("Skibidi dub dub dub yes yes", _Font, 200, 10, Red);
	Engine::Get().World().Draw();
	Engine::Get().Gfx().Present();
}
