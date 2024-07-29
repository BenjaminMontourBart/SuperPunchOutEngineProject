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
	
	m_Anim->AddClip("Punch", 5, 1, 0.3f);
	m_Anim->AddClip("FacePunch", 1, 1, 0.3f);
	m_Anim->AddClip("Win", 9, 1, 0.5f);
}

void Player::Update(float dt)
{
	m_Anim->SetPos(m_X, m_Y, 150, 300);
	m_Anim->SetFlip(m_FlipH, m_FlipV);

	Engine::Get().Collide().RectCollider(PlayerType, m_X, m_Y, m_W, m_H);


	if (m_End == false)
	{
		if (Engine::Get().Input().IsKeyDown(Homer::MyKey_UP) && m_Attack == false)
		{
			m_Anim->SetFrame("FaceBlock");
			m_TopDef = true;
		}
		else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_DOWN))
		{
			m_TopDef = false;
			m_Anim->SetFrame("Idle");

		}
		else if (m_Attack != true)
		{
			m_TopDef = false;
			m_Anim->SetFrame("Idle");
		}

		if (Engine::Get().Input().IsKeyDown(Homer::MyKey_LEFT))
		{
			m_FlipV = false;
			m_Anim->SetFrame("Dodge");
			m_X = 250;
			m_Invincible = true;
		}
		else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_RIGHT))
		{
			m_Anim->SetFrame("Dodge");
			m_FlipV = true;
			m_X = 450;
			m_Invincible = true;
		}
		else
		{
			m_Invincible = false;
			m_X = m_XStart;
			m_FlipV = false;
		}

		if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z) && !Engine::Get().Input().IsKeyDown(Homer::MyKey_UP))
		{
			m_Attack = true;
			m_Anim->Play("Punch", false);
			Position.Invoke(1);
		}
		else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z) && Engine::Get().Input().IsKeyDown(Homer::MyKey_UP))
		{
			m_Attack = true;
			m_Anim->Play("FacePunch", false);
			Position.Invoke(2);
		}
		else
		{
			m_Attack = false;
			m_Anim->Play("", false);
		}
	}
	else
	{
		m_EndTimer += dt;
		if (m_HP > 0)
		{
			m_Anim->Play("Win", false);
		}
		if (m_EndTimer > 3)
		{
			Engine::Get().Sound().StopMusic();
			Engine::Get().World().Load("Scene");
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
	m_Anim->Stop();
	if (value == 1 && m_TopDef == true && m_Invincible == false)
	{
		m_Anim->SetFrame("GetPunch");
		m_HP -= 10;
	}
	else if (value == 2 && m_TopDef == false && m_Invincible == false)
	{
		m_Anim->SetFrame("GetFacePunch");
		m_HP -= 10;
	}
	else if (value == 1 && m_TopDef == false && m_Invincible == false)
	{
		m_Anim->SetFrame("FaceBlock");
	}
	else if (value == 2 && m_TopDef == true && m_Invincible == false)
	{
		m_Anim->SetFrame("FaceBlock");
	}
}


