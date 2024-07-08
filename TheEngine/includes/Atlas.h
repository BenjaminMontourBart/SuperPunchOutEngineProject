#pragma once
#include "Sprite.h"
#include <string>

class Atlas :
    public Sprite
{
    void AddFrame(const std::string& name, int x, int y, int w, int h);
    void SetFrame(const std::string& name);
};

