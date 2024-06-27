#pragma once
#include "Entity.h"

class Player :
    public Entity
{
public:
    Player(int x, int y, int w, int h);
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Destroy() override;
private:
    float m_X = 0.0f;
    float m_Y = 0.0f;
    float Speed = 100;
    float H = 200;
    float W = 200;
};

