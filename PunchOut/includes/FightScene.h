#pragma once
#include "IScene.h"
#include "Player.h"
#include "Mechant.h"
#include "BackGround.h"

namespace Homer
{
    class FightScene :
        public IScene
    {
        ~FightScene();
        void Load() override;

    private:
        std::vector<Entity*> entity;
        Player* player;
        Mechant* enemy;
        BackGround* backGround;
    };
}

