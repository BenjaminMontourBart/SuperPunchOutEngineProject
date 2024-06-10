#include "Game.h"
#include "SDL.h"
#include "Windows.h"


void Game::Init(const std::string& title, int w, int h)
{
	m_Input = new SDLInput;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log(SDL_GetError());
	}

	Uint32 _flag = SDL_WINDOW_TOOLTIP;

	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;

	_window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);
	if (!_window)
	{
		SDL_Log(SDL_GetError());
	}

	_flag = SDL_RENDERER_ACCELERATED;
	_renderer = SDL_CreateRenderer(_window, -1, _flag);
	if (!_renderer)
	{
		SDL_Log(SDL_GetError());
	}
	exit = true;

	MoveX = 200;
	MoveY = 200;
}

void Game::Update(float dt)
{
	if (m_Input->IsKeyDown(Homer::MyKey_W))
	{
		MoveY -= 1;
	}
	if (m_Input->IsKeyDown(Homer::MyKey_S))
	{
		MoveY += 1;
	}
	if (m_Input->IsKeyDown(Homer::MyKey_A))
	{
		MoveX -= 1;
	}
	if (m_Input->IsKeyDown(Homer::MyKey_D))
	{
		MoveX += 1;
	}

	SDL_Event _event;

#ifdef DEBUG_MODE
	if (m_Input->IsKeyDown(Homer::MyKey_ESCAPE))
	{
		exit = false;
	}
#endif

	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			SDL_Log("allo");
			exit = false;
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

void Game::Render()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_Rect get_rekt = { 0 };
	get_rekt.x = MoveX;
	get_rekt.y = MoveY;
	get_rekt.w = 50;
	get_rekt.h = 50;
	SDL_RenderFillRect(_renderer, &get_rekt);
	SDL_RenderPresent(_renderer);
}

bool Game::Exit()
{
	return exit;
}
