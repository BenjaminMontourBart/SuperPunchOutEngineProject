#pragma once
#include "IGFX.h"

class SDLGFX : public IGFX
{
public:
    virtual void FillRect(float x1, float y1, float x2, float y2) = 0;
    virtual void DrawLine(float x1, float y1, float x2, float y2) = 0;
};