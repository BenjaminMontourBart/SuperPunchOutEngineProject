#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"

Homer::Sprite::Sprite(Entity* parent) : Component(parent)
{
    m_Flip.y = false;
    m_Flip.x = false;
}

void Homer::Sprite::Draw()
{
    double _rot = 0;
    RectF _dst = { m_X, m_Y, m_W, m_H };
    Graphics().DrawTexture(m_TextureId, m_Source, _dst, _rot, m_Flip, m_Color);
}

void Homer::Sprite::Load(const std::string& filename)
{
    m_TextureId = Graphics().LoadTexture(filename);
    Graphics().GetTextureSize(m_TextureId, &m_Source.w, &m_Source.h);
}

void Homer::Sprite::SetPos(float x, float y, float w, float h)
{
    m_X = x;
    m_Y = y;
    m_W = w;
    m_H = h;
}

void Homer::Sprite::SetColor(const Color& color)
{
    m_Color.Set(color);
}

void Homer::Sprite::SetFlip(bool h, bool v)
{
    m_Flip.y = h;
    m_Flip.x = v;
}
