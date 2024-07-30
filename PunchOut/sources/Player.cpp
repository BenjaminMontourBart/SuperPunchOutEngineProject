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
	m_W = static_cast<float>(w);
	m_H = static_cast<float>(h);

	m_XStart = m_X;
	//_SMusic = Engine::Get().Sound().LoadSound("assets/Chipeur.mp3");

	m_entity = Engine::Get().World().Create("Player");

	m_Anim = m_entity->AddComponent<Animation>();
	m_Anim->Init(1, 432, 176);
	m_Anim->Load("assets/Player.png");
	m_Anim->AddFrame("Punch1", 465, 149, 83, 102);
	m_Anim->AddFrame("Punch2", 549, 149, 73, 102);

	m_Anim->AddFrame("FacePunch1", 330, 285, 73, 102);
	m_Anim->AddFrame("FacePunch2", 405, 285, 62, 102);

	m_Anim->AddFrame("StopPunch", 72, 149, 59, 102);
	m_Anim->AddFrame("StopPunchFace", 399, 149, 59, 102);

	m_Anim->AddFrame("GetDamage", 101, 285, 83, 102);

	m_Anim->AddFrame("Win1", 2, 428, 83, 112);
	m_Anim->AddFrame("Win2", 80, 391, 74, 112);

	m_Anim->AddFrame("Idle", 8, 149, 64, 102);
	m_Anim->AddFrame("FaceBlock", 323, 149, 76, 102);
	m_Anim->AddFrame("Dodge", 183, 257, 69, 102);

	m_Anim->AddFrame("Defeat", 212, 172, 110, 79);

	m_Anim->AddClip("Punch", 6, 1, 0.3f);
	m_Anim->AddClip("FacePunch", 2, 1, 0.3f);
	m_Anim->AddClip("Win", 10, 1, 0.5f);

	m_Idle = true;
}

void Player::Update(float dt)
{
	m_Anim->SetPos(m_X, m_Y, 150, 300);
	m_Anim->SetFlip(m_FlipH, m_FlipV);

	Engine::Get().Collide().RectCollider(PlayerType, m_X, m_Y, m_W, m_H);

	if (m_HP <= 0)
	{
		m_End = true;
		Position.Invoke(3);
		m_Anim->SetFrame("Defeat");
	}
	if (m_End == true)
	{
		m_EndTimer += dt;
		if (m_HP > 0)
		{
			m_Anim->Play("Win", false);
		}
	}
	if (m_EndTimer > 3)
	{
		Engine::Get().Sound().StopMusic();
		Engine::Get().World().Unload();
		Engine::Get().World().Load("Scene");
	}

	if (m_End == false)
	{
		if (m_StunTime > 0)
		{
			m_Stun = true;
			m_StunTime -= dt;
		}
		else
		{
			m_Stun = false;
		}

		///////////////////////////////////////////////////////////////////// Idle
		if (m_Idle == true && m_Stun == false)
		{
			if (Engine::Get().Input().IsKeyDown(Homer::MyKey_UP))
			{
				m_Anim->SetFrame("FaceBlock");
				m_TopDef = true;
				//////////////////// Punch
				if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z))
				{
					m_Attack = true;
					m_Idle = false;
					m_TopPunch = true;
					m_Anim->Stop();
				}
			}
			else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_DOWN))
			{
				m_TopDef = false;
				m_Anim->SetFrame("Idle");
			}
			//////////////////////// dodge
			else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_LEFT))
			{
				m_DodgeLeft = true;
				m_Dodge = true;
				m_Idle = false;
				m_Invincible = true;
			}
			else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_RIGHT))
			{
				m_DodgeLeft = false;
				m_Dodge = true;
				m_Idle = false;
				m_Invincible = true;
			}

			////////////////////////// Punch 
			else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z))
			{
				m_Attack = true;
				m_Idle = false;
				m_TopPunch = false;
				m_Anim->Stop();
			}
			else
			{
				m_TopDef = false;
				m_FlipV = false;
				m_Anim->SetFrame("Idle");
			}
		}
		//////////////////////////////////////////////////////////////// Dodge
		if (m_Dodge == true && m_Stun == false)
		{
			m_TopDef = false;
			m_DodgeTimer += dt;

			if (m_DodgeLeft == true)
			{
				m_FlipV = false;
				m_X = 250;
				m_Anim->SetFrame("Dodge");
			}
			else
			{
				m_Anim->SetFrame("Dodge");
				m_FlipV = true;
				m_X = 450;
			}

			if (m_DodgeTimer > 0.5f)
			{
				m_DodgeTimer = 0;
				m_Invincible = false;
				m_FlipV = false;
				m_X = m_XStart;
				m_Dodge = false;
				m_Idle = true;
			}
		}

		///////////////////////////////////////////////////////////////// Attack
		if (m_Attack == true && m_Stun == false)
		{
			m_TopDef = false;
			if (m_TopPunch == false)
			{
				m_Anim->Play("Punch", false);
			}
			else
			{
				m_Anim->Play("FacePunch", false);
			}


			m_ActionTime += dt;
			if (m_ActionTime > 0.6f)
			{
				if (m_TopPunch == false)
				{
					Position.Invoke(1);
				}
				else
				{
					Position.Invoke(2);
				}
				m_ActionTime = 0;
				m_Attack = false;
				m_Idle = true;
			}
		}
	}
}

void Player::Draw()
{
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().DrawString(std::to_string(m_HP), _Font, 20, 10, Blue);
}
void Player::OnNotify(int value)
{
	if (value == 1 && m_TopDef == true && m_Invincible == false)
	{
		m_StunTime = 0.5;
		m_Anim->SetFrame("GetDamage");
		m_HP -= 10;
	}
	else if (value == 2 && m_TopDef == false && m_Invincible == false)
	{
		m_StunTime = 0.5;
		m_Anim->SetFrame("GetDamage");
		m_HP -= 10;
	}
	else if (value == 1 && m_TopDef == false && m_Invincible == false)
	{
		m_StunTime = 0.2;
		m_Anim->SetFrame("StopPunch");
	}
	else if (value == 2 && m_TopDef == true && m_Invincible == false)
	{
		m_StunTime = 0.2;
		m_Anim->SetFrame("StopPunchFace");
	}
	if (value == 3)
	{
		m_End = true;
	}
}


