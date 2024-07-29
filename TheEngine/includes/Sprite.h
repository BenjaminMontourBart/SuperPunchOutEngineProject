#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <Flip.h>
#include <RectI.h>
#include <string>

namespace Homer
{
    class Sprite : public Component, public IDrawable
    {
    public:
        virtual ~Sprite() = default;
        Sprite(Entity* parent);

        virtual void Draw() override;
        virtual void Load(const std::string& filename);

        void SetPos(float x, float y, float w, float h);

        void SetColor(const Color& color);
        void SetFlip(bool h, bool v);
        bool GetFlipH() const { return m_Flip.y; }
        bool GetFlipV() const { return m_Flip.x; }

    private:
        size_t m_TextureId = 0;
        Color m_Color{ 255, 255, 255, 255 };
        Flip m_Flip;

        float m_X = 0;
        float m_Y = 0;
        float m_W = 0;
        float m_H = 0;

    protected:
        RectI m_Source{ 0, 0, 0, 0 };
    };
}

