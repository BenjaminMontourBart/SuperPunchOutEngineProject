#include "Mechant.h"
#include "Engine.h"

using namespace Homer;

Mechant::Mechant(int x, int y, int w, int h)
{
	m_X = x;
	m_Y = y;
	W = w;
	H = h;
}

void Mechant::Start()
{
}

void Mechant::Update(float dt)
{
	Engine::Get().Collide().RectCollider(EnemyType, m_X, m_Y, W, H);
}

void Mechant::Draw()
{
	size_t _texture = Engine::Get().Gfx().LoadTexture("assets/Bogdanof.jpg");
	RectF Randrect = { m_X, m_Y, W, H };
	Engine::Get().Gfx().DrawTexture(_texture, Randrect, Red);
}

void Mechant::Destroy()
{
}
