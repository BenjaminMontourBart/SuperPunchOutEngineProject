#pragma once
#include "Atlas.h"
#include <string>

class Animation:
    public Atlas,
    public  IUpdatable
{
    void Update(float dt) override;
    void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
    void AddClip(const std::string& name, int start, int count, float delay);
    void Stop();
    void Play(const std::string& name, bool loop);

};

