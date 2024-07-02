#pragma once
#include "IScene.h"

class Scene :
    public IScene
{
    ~Scene();
    void Load() override;
    void Draw() override;
};

