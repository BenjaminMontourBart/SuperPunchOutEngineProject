#pragma once
#include "IScene.h"
#include "Player.h"
#include "Mechant.h"

class SceneTest :
    public IScene
{
    ~SceneTest();
    void Load() override;
    void Draw() override;

private:
    std::vector<Entity*> entity;
    Player* player;
    Mechant* enemy;
};

