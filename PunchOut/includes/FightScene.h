#pragma once
#include "IScene.h"
#include "Player.h"
#include "Mechant.h"

namespace Homer
{
    class FightScene :
        public IScene
    {
        ~FightScene();
        void Load() override;
        void Draw() override;

    private:
        std::vector<Entity*> entity;
        Player* player;
        Mechant* enemy;
    };
}

