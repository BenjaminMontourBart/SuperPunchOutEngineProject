#include "Player.h"
#include "Engine.h"
#include <string>

using namespace Homer;


Player::~Player()
{
}

void Player::Start(int x, int y, int w, int h)
{
	m_X = x;
	m_Y = y;
	W = w;
	H = h;
	_SMusic = Engine::Get().Sound().LoadSound("assets/Chipeur.mp3");
}

void Player::Update(float dt)
{

	Engine::Get().Collide().RectCollider(PlayerType, m_X, m_Y, W, H);
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_W))
	{
		m_Y -= Speed * dt;

		Engine::Get().Sound().SetVolume(_SMusic, 10);
		Engine::Get().Sound().PlaySFX(_SMusic);
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_S))
	{
		m_Y += Speed * dt;
	}
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_A))
	{
		m_X -= Speed * dt;
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_D))
	{
		m_X += Speed * dt;
	}
}

void Player::Draw()
{
	size_t _Ptexture = Engine::Get().Gfx().LoadTexture("assets/Patrique.jpg");
	RectF Rect = { m_X, m_Y, H, W };
	Engine::Get().Gfx().DrawTexture(_Ptexture, Rect, Red);
}


