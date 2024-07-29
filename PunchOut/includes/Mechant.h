#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Animation.h"
#include "Observer.h"

namespace Homer
{
    class Mechant :
        public Component,
        public IUpdatable,
        public IDrawable
    {
    public:
        ~Mechant();
        Mechant(Entity* parent) : Component(parent) {}
        virtual void Start(int x, int y, int w, int h);
        virtual void Update(float dt);
        virtual void Draw();

    private:

        Observer* m_Observer;
        Entity* entity;
        Animation* m_Anim;
        float m_X = 0.0f;
        float m_Y = 0.0f;
        float H = 0;
        float W = 0;
        float StartY = 0;
        float Timer = 0;
        float TimeGive = 0;

        int AttackCount = 0;

        float Random = 0;
        bool m_Idle = false;
        bool m_Attack = false;
    };
}

