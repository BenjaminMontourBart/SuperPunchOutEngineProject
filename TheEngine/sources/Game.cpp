#include "Game.h"
#include "Windows.h"
#include "Engine.h"
#include "Color.h"

using namespace Homer;

void Game::Init(const std::string& title, int w, int h)
{
	Engine::Get().Exit(true);
	
	MoveX = 200;
	MoveY = 200;
	Engine::Get().Sound().PlayMusic(-1);
}

void Game::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_W))
	{
		MoveY -= Speed * dt;

		Engine::Get().Sound().SetVolume(10);
		Engine::Get().Sound().PlaySFX(0);
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_S))
	{
		MoveY += Speed * dt;
	}
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_A))
	{
		MoveX -= Speed * dt;
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_D))
	{
		MoveX += Speed * dt;
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
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("oopsi.jpg");
	size_t _texture = Engine::Get().Gfx().LoadTexture("Patrique.jpg");
	Engine::Get().Gfx().Clear();
	Engine::Get().Gfx().DrawTexture(_Btexture,Red);
	RectF rect = { MoveX, MoveY, H, W };
	Engine::Get().Gfx().DrawTexture(_texture, rect, Red);
	Engine::Get().Gfx().Present();
}
