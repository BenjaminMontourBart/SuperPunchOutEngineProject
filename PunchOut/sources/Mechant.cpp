#include "Mechant.h"
#include "Engine.h"
#include <iostream>

using namespace Homer;


Mechant::~Mechant()
{

}

void Mechant::Start(int x, int y, int w, int h)
{
	m_X = static_cast<float>(x);
	m_Y = static_cast<float>(y);
	m_W = static_cast<float>(w);
	m_H = static_cast<float>(h);
	m_StartY = m_Y;
	m_entity = Engine::Get().World().Create("Enemy");

	m_SMusic = Engine::Get().Sound().LoadSound("assets/ComeOn.wav");

	m_Anim = m_entity->AddComponent<Animation>();

	m_Anim->Init(1, 432, 176);
	m_Anim->Load("assets/GabbyJay.png");

	m_Anim->AddFrame("Idle1", 7, 0, 66, 169);
	m_Anim->AddFrame("Idle2", 74, 0, 66, 169);
	m_Anim->AddFrame("Idle3", 150, 0, 66, 169);
	m_Anim->AddFrame("Idle4", 224, 0, 66, 169);

	m_Anim->AddFrame("Dodge1", 308, 0, 66, 169);
	m_Anim->AddFrame("Dodge2", 383, 0, 72, 169);

	m_Anim->AddFrame("FaceBlock", 5, 178, 72, 169);
	m_Anim->AddFrame("Block", 76, 178, 72, 169);

	m_Anim->AddFrame("NormalPunch1", 7, 363, 72, 169);
	m_Anim->AddFrame("NormalPunch2", 84, 363, 72, 169);

	m_Anim->AddFrame("Special1", 0, 707, 72, 169);
	m_Anim->AddFrame("Special2", 78, 707, 72, 169);
	m_Anim->AddFrame("Special3", 182, 707, 72, 169);

	m_Anim->AddFrame("ComeOnMove1", 0, 877, 72, 169);
	m_Anim->AddFrame("ComeOnMove2", 73, 877, 72, 169);
	m_Anim->AddFrame("ComeOnMove3", 158, 877, 85, 169);
	m_Anim->AddFrame("ComeOnMove4", 255, 877, 85, 169);
	m_Anim->AddFrame("ComeOnMove5", 346, 877, 74, 169);
	m_Anim->AddFrame("ComeOnMove6", 430, 877, 74, 169);

	m_Anim->AddFrame("Down1", 157, 1592, 75, 172);
	m_Anim->AddFrame("Down2", 248, 1592, 86, 172);
	m_Anim->AddFrame("Down3", 334, 1592, 77, 172);
	m_Anim->AddFrame("Down4", 419, 1592, 85, 172);
	m_Anim->AddFrame("Down5", 2, 1777, 108, 172);

	m_Anim->AddFrame("GetFacePunch", 0, 1598, 72, 169);
	m_Anim->AddFrame("GetPunch", 75, 1598, 72, 169);

	m_Anim->AddClip("Idle", 16, 3, 0.3f);
	m_Anim->AddClip("NormalPunch", 20, 1, 0.5f);
	m_Anim->AddClip("SpecialPunch", 22, 2, 0.5f);
	m_Anim->AddClip("ComeOnMove1", 0, 1, 0.7f);
	m_Anim->AddClip("ComeOnMove2", 2, 3, 0.5f);
	m_Anim->AddClip("Down", 8, 4, 0.5f);

	m_Idle = true;
}

void Mechant::Update(float dt)
{

	m_Anim->SetPos(m_X, m_Y, 150, 300);
	DefTimerChange += dt;
	if (DefTimerChange > 1)
	{
		DefTimerChange = 0;
		if (m_TopDef == true)
		{
			m_TopDef = false;
		}
		else
		{
			m_TopDef = true;
		}
	}
	if (m_Idle)
	{
		m_Anim->Play("Idle", true);
		m_Timer += dt;
		if (m_Timer >= 3)
		{
			m_Timer = 0;
			m_Random = rand() % 2;
			m_Idle = false;
			m_Attack = true;
		}
	}
	else if (m_Attack)
	{
		m_Timer += dt;
		m_TimeGive = 1;
		if (m_AttackCount >= 3)
		{
			m_Invincible = true;
			if (m_Timer < 1)
			{
				m_Y -= 50 * dt;
				m_Anim->Play("ComeOnMove1", false);
			}
			else if (m_Y < m_StartY)
			{
				if (m_Music == false)
				{
					m_Music = true;
					Engine::Get().Sound().SetVolume(m_SMusic, 20);
					Engine::Get().Sound().PlaySFX(m_SMusic);
				}
				m_Y += 70 * dt;
				m_Anim->Play("ComeOnMove2", false);
				Position.Invoke(1);
			}
			else if (m_Y > m_StartY)
			{
				m_Y = m_StartY;
			}

			m_TimeGive = 3;
			if (m_Timer >= m_TimeGive)
			{
				m_Music = false;
				m_Random = -1;
				m_AttackCount = -1;
				m_Invincible = false;
			}
		}
		else if (m_Random == 0)
		{
			m_Anim->Play("NormalPunch", false);
			Position.Invoke(1);
		}
		else if (m_Random == 1)
		{
			m_Anim->Play("SpecialPunch", false);
			Position.Invoke(2);
		}

		if (m_Timer >= m_TimeGive)
		{
			m_AttackCount += 1;
			m_Timer = 0;
			m_Idle = true;
			m_Attack = false;
		}
	}
}

void Mechant::Draw()
{
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().DrawString(std::to_string(m_HP), _Font, 700, 10, Red);
}



void Homer::Mechant::OnNotify(int value)
{
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
}


