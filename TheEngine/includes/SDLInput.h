#pragma once
#include "Engine.h"
#include "IInput.h"
#include <vector>

class SDLInput : public  Homer::IInput
{
public:
    virtual int IsKeyDown(int key);
protected:
    void Init();
    virtual void Update();
private:
    const unsigned char* m_keystates;
    bool m_OnTouch = false;
};