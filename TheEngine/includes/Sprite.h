#pragma once
#include "Engine.h"
#include "Component.h"

using namespace Homer;

class Sprite
	:public Component,
	public  IDrawable
{

private:
	void load();
	void Draw() override;

protected:
	size_t Ptexture = Engine::Get().Gfx().LoadTexture("Chaplin.png");
	RectI source;
	RectF destination;
};
