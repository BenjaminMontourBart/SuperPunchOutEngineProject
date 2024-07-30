#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Animation.h"
#include "Observer.h"
#include "Subject.h"

namespace Homer
{
    class Player :
        public Component,
        public IUpdatable,
        public IDrawable,
        public Observer<int>
    {
    public:
        ~Player();
        Player(Entity* parent) : Component(parent) {}
        virtual void Start(int x, int y, int w, int h);
        virtual void Update(float dt);
        virtual void Draw();

        void OnNotify(int value) override;

        Subject<int> Position;

    private:

        Entity* m_entity;
        Animation* m_Anim;
        size_t m_SMusic;
        float m_XStart;
        float m_X = 0.0f;
        float m_Y = 0.0f;
        float m_H = 200;
        float m_W = 200;
        float m_Speed = 100;
        bool m_FlipH = false;
        bool m_FlipV = false;
        bool m_Left = false;
        bool m_Right = false;
        bool m_TopDef = false;
        bool m_Invincible = false;
        int m_HP = 100;
        float m_EndTimer = 0;
        bool m_Idle = false;
        bool m_Attack = false;
        bool m_Dodge = false;
        bool m_DodgeLeft = false;
        float m_DodgeTimer = 0;
        float m_ActionTime = 0;
        float m_StunTime = 0;
        bool m_Stun = false;

        bool m_TopPunch = false;

        bool m_End = false;
    };
}

