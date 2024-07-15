#include "Mechant.h"
#include "Engine.h"

using namespace Homer;


Mechant::~Mechant()
{
}

void Mechant::Start(int x, int y, int w, int h)
{
	m_X = x;
	m_Y = y;
	W = w;
	H = h;
}

void Mechant::Update(float dt)
{
	if (Engine::Get().Collide().RectCollider(EnemyType, m_X, m_Y, W, H) == true)
	{

	}
}

void Mechant::Draw()
{
	size_t _texture = Engine::Get().Gfx().LoadTexture("assets/Bogdanof.jpg");
	RectF Randrect = { m_X, m_Y, W, H };
	Engine::Get().Gfx().DrawTexture(_texture, Randrect, Red);
}
