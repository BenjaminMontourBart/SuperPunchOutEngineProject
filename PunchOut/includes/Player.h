#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Animation.h"
#include "Subject.h"

namespace Homer
{
    class Player :
        public Component,
        public IUpdatable,
        public IDrawable
    {
    public:
        ~Player();
        Player(Entity* parent) : Component(parent) {}
        virtual void Start(int x, int y, int w, int h);
        virtual void Update(float dt);
        virtual void Draw();

        //Subject<int> Position;

    private:

        Entity* entity;
        Animation* m_Anim;
        size_t _SMusic;
        float XStart;
        float m_X = 0.0f;
        float m_Y = 0.0f;
        float H = 200;
        float W = 200;
        float Speed = 100;
        bool FlipH = false;
        bool FlipV = false;
        int HP = 100;
        float EndTimer = 0;
        bool Attack = false;

        bool End = false;
    };
}

