#include "Engine.h"
#include "Game.h"
#include <time.h>
#include "Windows.h"
#include <iostream>
#include <fstream>
#include "SDLInput.h"
#include "SDLGFX.h"
#include "Console.h"
#include "Audio.h"
#include "Collision.h"
#include "WorldService.h"


static Game* m_Game = nullptr;

//Homer::Engine& Homer::Engine::Get()
//{
//	static Engine Instance;
//	return Instance;
//}

Homer::Engine::~Engine()
{
	if (m_Audio != nullptr)
	{
		delete m_Audio;
		m_Audio = nullptr;
	}
	if (m_Logger != nullptr)
	{
		delete m_Logger;
		m_Logger = nullptr;
	}
	if (m_Gfx != nullptr)
	{
		delete m_Gfx;
		m_Gfx = nullptr;
	}
	if (m_Animation != nullptr)
	{
		delete m_Animation;
		m_Animation = nullptr;
	}
	if (m_Atlas != nullptr)
	{
		delete m_Atlas;
		m_Atlas = nullptr;
	}
	if (m_Input != nullptr)
	{
		delete m_Input;
		m_Input = nullptr;
	}
	if (m_Collide != nullptr)
	{
		delete m_Collide;
		m_Collide = nullptr;
	}
	if (m_World != nullptr)
	{
		delete m_World;
		m_World = nullptr;
	}
	
}

bool Homer::Engine::Init(const std::string& title, int w, int h)
{
	m_World = new WorldService;
	m_Audio = new Audio;
	m_Gfx = new SDLGFX();
	m_Animation = new Animation();
	m_Atlas = new Atlas();
	m_Gfx->Initialize(title, w, h);
	m_Collide = new Collision();
	m_Logger = new Console();
	m_Input = new SDLInput();
	m_Game = new Game();
	m_Game->Init(title, w, h);

	Timer = 0;
	m_IsInit = true;

	return true;
}

void Homer::Engine::Start()
{
	if (!m_IsInit)
	{
		if (Init("Unknown title", 800, 600))
		{
			return;
		}
	}
	m_IsRunning = true;

	///
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	///
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	///
	std::ofstream MyFile("filename.txt");
	MyFile << "Files can be tricky, but it is fun enough!";
	MyFile.close();
	////////////////



	clock_t _end = clock();
	////////////////////////////////////////// IsRunning(TheGame Run Here) ////////////////
	while (m_IsRunning)
	{
		const clock_t start = clock();
		/////////////////////////////////////////// Calcul du DeltaTime /////////////
		float _dt = (start - _end) * 0.001f;
		m_Input->Update();
		Update(_dt);
		m_World->Update(_dt);
		m_Game->Update(_dt);
		Render();
		////////////////////////////////////////// la difference entre 2 frame /////////////
		SleepTime = 16.6f - (_dt * 1000);
		if (SleepTime > 0.0f)
		{
			Sleep(SleepTime);
		}
		_end = start;
	}
	Shutdown();
}


void Homer::Engine::Update(float dt)
{
}

void Homer::Engine::Render()
{
	m_Game->Render();
}

void Homer::Engine::Shutdown()
{
	delete m_Game;
}

void Homer::Engine::Exit()
{
	m_IsRunning = false;
}
