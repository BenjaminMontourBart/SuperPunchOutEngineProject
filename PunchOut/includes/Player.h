#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"

namespace Homer
{
    class Player :
        public Component,
        public IUpdatable,
        public IDrawable
    {
    public:
        ~Player();
        Player() = default;
        virtual void Start(int x, int y, int w, int h);
        virtual void Update(float dt);
        virtual void Draw();
    private:
        size_t _SMusic;
        float m_X = 0.0f;
        float m_Y = 0.0f;
        float H = 200;
        float W = 200;
        float Speed = 100;
    };
}

