#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Animation.h"

namespace Homer
{
    class UI:
        public Component,
        public IUpdatable,
        public IDrawable
    {
    public:
        UI(Entity* parent) : Component(parent) {}
        virtual void Update(float dt);

    private:
    };
}

