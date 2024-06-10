#include "SDLInput.h"
#include "SDL.h"

int SDLInput::IsKeyDown(int key)
{
	const unsigned char* _keystates = SDL_GetKeyboardState(nullptr);

	if (_keystates[key])
	{
		return key;
	}
}

void SDLInput::Init()
{
}

void SDLInput::Update()
{
}
