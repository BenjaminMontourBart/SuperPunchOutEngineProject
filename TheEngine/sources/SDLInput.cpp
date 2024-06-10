#include "SDLInput.h"
#include "SDL.h"
#include "Engine.h"

int SDLInput::IsKeyDown(int key)
{
	return m_keystates[key];
}

void SDLInput::Init()
{
}

void SDLInput::Update()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			Homer::Engine::Get().Exit(false);
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _ButtonDown = _event.button;
			SDL_Log("button down : %d)", _ButtonDown.button);
			SDL_Log("at (%d, %d)", _ButtonDown.x, _ButtonDown.y);
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _ButtonUp = _event.button;
			SDL_Log("button Up : %d)", _ButtonUp.button);
			SDL_Log("at (%d, %d)", _ButtonUp.x, _ButtonUp.y);
			break;

		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _Motion = _event.motion;
			SDL_Log("Mobility : %d, %d", _Motion.x, _Motion.y);
			break;
		}
	}
}
