#include "Mechant.h"
#include "Engine.h"

using namespace Homer;


Mechant::~Mechant()
{

}

void Mechant::Start(int x, int y, int w, int h)
{
	m_X = static_cast<float>(x);
	m_Y = static_cast<float>(y);
	W = static_cast<float>(w);
	H = static_cast<float>(h);
}

void Mechant::Update(float dt)
{
	if (Engine::Get().Collide().RectCollider(EnemyType, m_X, m_Y, W, H) == true)
	{
		/*delete this;*/
	}
}

void Mechant::Draw()
{
	size_t _texture = Engine::Get().Gfx().LoadTexture("assets/Bogdanof.jpg");
	RectF Randrect = { m_X, m_Y, W, H };
	//Engine::Get().Gfx().DrawTexture(_texture, Randrect, Red);
}
