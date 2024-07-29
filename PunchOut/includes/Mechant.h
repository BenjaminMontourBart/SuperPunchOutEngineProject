#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Animation.h"
#include "Observer.h"
#include "Subject.h"

namespace Homer
{
    class Mechant :
        public Component,
        public IUpdatable,
        public IDrawable,
        public Observer<int>
    {
    public:
        ~Mechant();
        Mechant(Entity* parent) : Component(parent) {}
        virtual void Start(int x, int y, int w, int h);
        virtual void Update(float dt);
        virtual void Draw();
  
        void OnNotify(int value) override;

        Subject<int> Position;

    private:

        Entity* m_entity;
        Animation* m_Anim;
        size_t m_SMusic;
        float m_X = 0.0f;
        float m_Y = 0.0f;
        float m_H = 0;
        float m_W = 0;
        float m_StartY = 0;
        float m_Timer = 0;
        float m_TimeGive = 0;
        int m_HP = 100;
        int m_AttackCount = 0;
        float DefTimerChange = 0;
        bool m_TopDef = false;
        bool m_Invincible = false;
        int m_Random = 0;
        bool m_Idle = false;
        bool m_Attack = false;
        bool m_Music = false;
    };
}

