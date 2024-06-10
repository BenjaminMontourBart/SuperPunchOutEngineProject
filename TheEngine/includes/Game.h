#pragma once
#include "SDLInput.h"
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Game
{
public:

	void Init(const std::string& title, int w, int h);
	void Update(float dt);
	void Render();
	bool Exit();
private:

	int MoveX;
	int MoveY;
	bool exit;

	SDLInput* m_Input;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};
