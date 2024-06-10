#pragma once
#include <string>
#include "ISound.h"

class Game
{
public:

	void Init(const std::string& title, int w, int h);
	void Update(float dt);
	void Render();

private:

	float Speed = 100;
	float MoveX;
	float MoveY;
	float H = 200;
	float W = 200;
};
