#include "Game.h"
#include "Windows.h"
#include "Engine.h"
#include "Color.h"
#include "Player.h"
#include "Mechant.h"
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


	size_t _BMusic = Engine::Get().Sound().LoadMusic("assets/CottonEyeJoe.mp3");
	Engine::Get().Sound().PlayMusic(_BMusic);

	for (int i = 0; i < m_EntityVector.size(); i++)
	{
		Engine::Get().World().Add(m_EntityVector[i]);
		m_EntityVector[i]->Start();
	}

	m_Entity = new Player(300, 300, 200, 200);
	m_EntityVector.push_back(m_Entity);
	Engine::Get().Collide().RectCollider(300, 300, 200, 200);
	m_Entity = new Mechant(100, 100, 100, 100);
	m_EntityVector.push_back(m_Entity);
	Engine::Get().Collide().RectCollider(100, 100, 100, 100);
}

void Game::Update(float dt)
{
	for (int i = 0; i < m_EntityVector.size(); i++)
	{
		m_EntityVector[i]->Update(dt);
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
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().Clear();
	Engine::Get().Gfx().DrawTexture(_Btexture, Red);
	Engine::Get().Gfx().DrawString("Skibidi dub dub dub yes yes", _Font, 200, 10, Red);
	for (int i = 0; i < m_EntityVector.size(); i++)
	{
		m_EntityVector[i]->Draw();
	}
	Engine::Get().Gfx().Present();
}
