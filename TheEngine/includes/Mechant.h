#pragma once
#include "Component.h"

class Mechant :
    public Component
{
public:
    Mechant() = default;
    virtual void Start(int x, int y, int w, int h);
    virtual void Update(float dt);
    virtual void Draw();
private:
    float m_X = 0.0f;
    float m_Y = 0.0f;
    float H = 0;
    float W = 0;

};

