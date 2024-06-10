
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include "Engine.h"

#ifdef DEBUG

#include "vld.h"

#endif // DEBUG


void InitGameplay()
{
	
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT)
{
	Homer::Engine& theEngine = Homer::Engine::Get();
	if (theEngine.Init("Test Game", 800, 600))
	{
		InitGameplay();
		theEngine.Start();
	}

	return 0;
}