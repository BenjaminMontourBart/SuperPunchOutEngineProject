#include <Atlas.h>
#include <Engine.h>

Homer::Atlas::Atlas() : Atlas(nullptr)
{
}

Homer::Atlas::Atlas(Entity* parent) : Sprite(parent)
{
}

void Homer::Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
    m_Frames.emplace(name, RectI{ x, y, w, h });

    if (m_Frames.size() == 1)
    {
        SetFrame(name);
    }
}

void Homer::Atlas::SetFrame(const std::string& name)
{
    RectI _src = m_Frames[name];
    m_Source.x = _src.x;
    m_Source.y = _src.y;
    m_Source.w = _src.w;
    m_Source.h = _src.h;
}
