#include "Player.h"
#include "Engine.h"
#include <string>

using namespace Homer;


Player::~Player()
{
}
static size_t _Ptexture;
void Player::Start(int x, int y, int w, int h)
{
	m_X = static_cast<float>(x);
	m_Y = static_cast<float>(y);
	W = static_cast<float>(w);
	H = static_cast<float>(h);
	_SMusic = Engine::Get().Sound().LoadSound("assets/Chipeur.mp3");
	size_t _Ptexture = Engine::Get().Gfx().LoadTexture("assets/Patrique.jpg");
}

void Player::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_P))
	{
		Engine::Get().World().Load("SceneTest");
	}

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
	RectF Rect = { m_X, m_Y, H, W };
	//Engine::Get().Gfx().DrawTexture(_Ptexture, Rect, Red);
}


