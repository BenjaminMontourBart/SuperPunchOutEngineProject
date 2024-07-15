#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"

Homer::Sprite::Sprite() : Sprite(nullptr)
{
}

Homer::Sprite::Sprite(Entity* parent) : Component(parent)
{
    m_Flip.y = false;
    m_Flip.x = false;
}

void Homer::Sprite::Draw()
{
    //double _rot = m_Entity->GetRotation();
    double _rot = 0;
    RectF _dst = {0, 0, 800, 600};
    //m_Entity->GetRect(&_dst);

    Graphics().DrawTexture(m_TextureId, m_Source, _dst, _rot, m_Flip, m_Color);
}

void Homer::Sprite::Load(const std::string& filename)
{
    m_TextureId = Graphics().LoadTexture(filename);
    Graphics().GetTextureSize(m_TextureId, &m_Source.w, &m_Source.h);
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
