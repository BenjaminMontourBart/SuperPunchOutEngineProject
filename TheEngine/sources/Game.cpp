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
	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);
}

void Game::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_W))
	{
		MoveY -= Speed * dt;

		size_t _SMusic = Engine::Get().Sound().LoadSound("assets/Chipeur.mp3");
		Engine::Get().Sound().SetVolume(_SMusic, 10);
		Engine::Get().Sound().PlaySFX(_SMusic);
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
	size_t _Btexture = Engine::Get().Gfx().LoadTexture("assets/oopsi.jpg");
	size_t _texture = Engine::Get().Gfx().LoadTexture("assets/Patrique.jpg");
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().Clear();
	Engine::Get().Gfx().DrawTexture(_Btexture,Red);
	Engine::Get().Gfx().DrawString("Skibidi dub dub dub yes yes", _Font, 200, 10, Red);
	RectF rect = { MoveX, MoveY, H, W };
	Engine::Get().Gfx().DrawTexture(_texture, rect, Red);
	Engine::Get().Gfx().Present();
}
