#pragma once
#include "IScene.h"

class SceneTest :
    public IScene
{
    ~SceneTest();
    void Load() override;
    void Draw() override;
};

