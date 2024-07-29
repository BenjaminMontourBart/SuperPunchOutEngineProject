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
	W = static_cast<float>(w);
	H = static_cast<float>(h);
	StartY = m_Y;
	entity = Engine::Get().World().Create("Enemy");

	_SMusic = Engine::Get().Sound().LoadSound("assets/ComeOn.wav");

	m_Anim = entity->AddComponent<Animation>();

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

	m_Anim->AddFrame("GetFacePunch", 0, 1598, 72, 169);
	m_Anim->AddFrame("GetPunch", 75, 1598, 72, 169);

	m_Anim->AddClip("Idle", 11, 3, 0.3f);
	m_Anim->AddClip("NormalPunch", 15, 1, 0.5f);
	m_Anim->AddClip("SpecialPunch", 17, 2, 0.5f);
	m_Anim->AddClip("ComeOnMove1", 1, 1, 0.7f);
	m_Anim->AddClip("ComeOnMove2", 3, 5, 0.5f);

	m_Anim->Play("Idle", true);

	m_Idle = true;
}

void Mechant::Update(float dt)
{

	m_Anim->SetPos(m_X, m_Y, 150, 300);

	if (m_Idle)
	{
		m_Anim->Play("Idle", true);
		Timer += dt;
		if (Timer >= 3)
		{
			Timer = 0;
			Random = rand() % 2;
			m_Idle = false;
			m_Attack = true;
		}
	}
	else if (m_Attack)
	{
		Timer += dt;
		TimeGive = 1;
		if (AttackCount >= 3)
		{
			if (Timer < 1)
			{
				m_Y -= 50 * dt;
				m_Anim->Play("ComeOnMove1", false);
			}
			else if (m_Y < StartY)
			{
				if (music == false)
				{
					music = true;
					Engine::Get().Sound().SetVolume(_SMusic, 20);
					Engine::Get().Sound().PlaySFX(_SMusic);
				}
				m_Y += 70 * dt;
				m_Anim->Play("ComeOnMove2", false);
			}
			else if (m_Y > StartY)
			{
				m_Y = StartY;
			}

			TimeGive = 3;
			if (Timer >= TimeGive)
			{
				music = false;
				Random = -1;
				AttackCount = -1;
			}
		}
		else if (Random == 0)
		{
			m_Anim->Play("NormalPunch", false);
		}
		else if (Random == 1)
		{
			m_Anim->Play("SpecialPunch", false);
		}

		if (Timer >= TimeGive)
		{
			AttackCount += 1;
			Timer = 0;
			m_Idle = true;
			m_Attack = false;
		}
	}
}

void Mechant::Draw()
{
	size_t _Font = Engine::Get().Gfx().LoadFont("assets/punch-out-nes.ttf", 12);
	Engine::Get().Gfx().DrawString(std::to_string(HP), _Font, 700, 10, Red);
}


