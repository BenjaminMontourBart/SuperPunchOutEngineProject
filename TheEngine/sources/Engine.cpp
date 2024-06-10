#include "Engine.h"
#include <time.h>
#include "Windows.h"
#include <iostream>
#include <fstream>

bool Homer::Engine::Init(const std::string& title, int w, int h)
{

	m_Game = new Game;
	m_Game->Init(title, w, h);

	Timer = 0;

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

	///////////////
	/*Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Music *music; 
	music = Mix_LoadMUS("music.mp3");
	Mix_CloseAudio();*/
	///
	/*TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
	if (m_FontCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_FontCache[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), _color);
	}*/
	///
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	///
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	///
	std::ofstream MyFile("filename.txt");
	MyFile << "Files can be tricky, but it is fun enough!";
	MyFile.close();
	////////////////


	AllocConsole();
	clock_t _end = clock();
	////////////////////////////////////////// IsRunning(TheGame Run Here) ////////////////
	while (m_IsRunning)
	{
		const clock_t start = clock();
		/////////////////////////////////////////// Calcul du DeltaTime /////////////
		float _dt = (start - _end) * 0.001f;

		Update(_dt);
		m_Game->Update(_dt);
		Render();
		////////////////////////////////////////// la difference entre 2 frame /////////////
		SleepTime = 16.6f - (_dt * 1000);
		if (SleepTime > 0)
		{
			Sleep(SleepTime);
		}
		_end = start;
	}
	Shutdown();
}


void Homer::Engine::Update(float dt)
{
	Exit();
}

void Homer::Engine::Render()
{
	m_Game->Render();
}

void Homer::Engine::Shutdown()
{
	FreeConsole();

}

void Homer::Engine::Exit()
{
	m_IsRunning = m_Game->Exit();
}
