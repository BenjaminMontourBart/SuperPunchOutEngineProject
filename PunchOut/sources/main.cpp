
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include "Engine.h"
#include "Scene.h"
#include "FightScene.h"

#ifdef _DEBUG

#include "vld.h"

#endif // DEBUG

using namespace Homer;

void InitGameplay()
{
	Engine::Get().World().Register("Scene", new Scene());
	Engine::Get().World().Register("SceneTest", new FightScene());
	Engine::Get().World().Load("Scene");
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