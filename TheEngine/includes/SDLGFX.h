#pragma once
#include "IGFX.h"
#include "SDL_render.h"
#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

namespace Homer
{
    class SDLGFX : public IGFX
    {
    public:
        ~SDLGFX();
        virtual bool Initialize(const std::string& title, int w, int h);
        virtual void Shutdown();
        virtual void SetColor(const Color& color);
        virtual void Clear();
        virtual void Present();
        virtual void DrawRect(float x, float y, float w, float h, const Color& color);
        virtual void DrawRect(const RectF& rect, const Color& color);
        virtual void FillRect(float x, float y, float w, float h, const Color& color);
        virtual void FillRect(const RectF& rect, const Color& color);
        virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color);
        virtual size_t LoadTexture(const std::string& filename);
        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color);
        virtual void DrawTexture(size_t id, const RectF& dst, const Color& color);
        virtual void DrawTexture(size_t id, const Color& color);
        virtual void GetTextureSize(size_t id, int* w, int* h);
        virtual size_t LoadFont(const std::string& filename, int fontSize);
        virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color);
        virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h);

    private:
        SDL_Renderer* m_Renderer;
        SDL_Window* m_Window;

        std::map<size_t, SDL_Texture*> m_TextureCache;
        std::map<size_t, TTF_Font*> m_FontCache;
    };
}