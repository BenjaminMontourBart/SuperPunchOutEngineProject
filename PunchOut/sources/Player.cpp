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

	XStart = m_X;
	//_SMusic = Engine::Get().Sound().LoadSound("assets/Chipeur.mp3");

	entity = Engine::Get().World().Create("Player");

	m_Anim = entity->AddComponent<Animation>();
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
	m_Anim->AddFrame("Win2", 80, 391, 74, 49);

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
	m_Anim->SetFlip(FlipH, FlipV);

	Engine::Get().Collide().RectCollider(PlayerType, m_X, m_Y, W, H);
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_UP) && Attack == false)
	{	
		m_Anim->SetFrame("FaceBlock");

		/*Engine::Get().Sound().SetVolume(_SMusic, 10);
		Engine::Get().Sound().PlaySFX(_SMusic);*/
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_DOWN))
	{
		m_Anim->SetFrame("Idle");

	}
	else if (Attack != true)
	{
		m_Anim->SetFrame("Idle");
	}
	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_LEFT))
	{
		FlipV = false;
		m_Anim->SetFrame("Dodge");
		m_X = 250;
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_RIGHT))
	{
		m_Anim->SetFrame("Dodge");
		FlipV = true;
		m_X = 450;
	}
	else
	{
		m_X = XStart;
		FlipV = false;
	}

	if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z) && !Engine::Get().Input().IsKeyDown(Homer::MyKey_UP))
	{
		Attack = true;
		m_Anim->Play("Punch", false);
	}
	else if (Engine::Get().Input().IsKeyDown(Homer::MyKey_Z) && Engine::Get().Input().IsKeyDown(Homer::MyKey_UP))
	{
		Attack = true;
		m_Anim->Play("FacePunch", false);
	}
	else
	{
		Attack = false;
		m_Anim->Play("", false);
	}

}

void Player::Draw()
{
}


