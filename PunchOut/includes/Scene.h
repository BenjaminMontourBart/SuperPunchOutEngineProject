#pragma once
#include "IScene.h"
#include "Player.h"
#include "Mechant.h"
#include <vector>

namespace Homer
{
    class Scene :
        public IScene
    {
        ~Scene();
        void Load() override;
        void Update(float dt) override;

    private:
        std::vector<Entity*> entity;
        Player* player;
        Mechant* enemy;
    };
}

