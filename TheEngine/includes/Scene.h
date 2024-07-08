#pragma once
#include "IScene.h"
#include "Player.h"
#include "Mechant.h"
#include <vector>

class Scene :
    public IScene
{
    ~Scene();
    void Load() override;
    void Draw() override;

private:
    std::vector<Entity*> entity;
    Player* player;
    Mechant* enemy;
};

