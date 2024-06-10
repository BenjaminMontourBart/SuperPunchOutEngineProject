#include "SDLGFX.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Color.h"


bool SDLGFX::Initialize(const std::string& title, int w, int h)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log(SDL_GetError());
	}

	Uint32 _flag = SDL_WINDOW_TOOLTIP;

	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;

	_window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);
	if (!_window)
	{
		SDL_Log(SDL_GetError());
	}
	_flag = SDL_RENDERER_ACCELERATED;
	m_Renderer = SDL_CreateRenderer(_window, -1, _flag);
	if (!m_Renderer)
	{
		SDL_Log(SDL_GetError());
	}

	return false;
}

void SDLGFX::Shutdown()
{
}

void SDLGFX::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.red, color.green, color.blue, 255);
}

void SDLGFX::Clear()
{
	SDL_RenderClear(m_Renderer);
}

void SDLGFX::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void SDLGFX::DrawRect(float x, float y, float w, float h, const Color& color)
{
}

void SDLGFX::DrawRect(const RectF& rect, const Color& color)
{

}

void SDLGFX::FillRect(int x, int y, int w, int h, const Color& color)
{
	SDL_Rect get_rekt = { 0 };
	get_rekt.x = x;
	get_rekt.y = y;
	get_rekt.w = w;
	get_rekt.h = h;
}

void SDLGFX::FillRect(const RectF& rect, const Color& color)
{
}

void SDLGFX::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t SDLGFX::LoadTexture(const std::string& filename)
{
	const size_t _textureId = std::hash<std::string>()(filename);
	if (m_TextureCache.count(_textureId) > 0)
	{
		return _textureId;
	}
	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
	m_TextureCache.emplace(_textureId, _texture);
	return _textureId;
}

void SDLGFX::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	Uint8 r = color.red;
	Uint8 g = color.green;
	Uint8 b = color.blue;
	Uint8 a = color.alpha;

	SDL_Rect Src = { src.x, src.y, src.w, src.h};
	SDL_Rect Dst = { dst.x, dst.y, dst.w, dst.h };
	SDL_RendererFlip Flip = SDL_FLIP_NONE;

	SDL_GetTextureColorMod(m_TextureCache[id], &r, &g, &b);
	SDL_GetTextureAlphaMod(m_TextureCache[id], &a);
	SDL_RenderCopyEx(m_Renderer, m_TextureCache[id], &Src, &Dst, 0, nullptr, Flip);
}

void SDLGFX::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	Uint8 r = color.red;
	Uint8 g = color.green;
	Uint8 b = color.blue;
	Uint8 a = color.alpha;

	SDL_Rect Dst = { dst.x, dst.y, dst.w, dst.h };

	SDL_GetTextureColorMod(m_TextureCache[id], &r, &g, &b);
	SDL_GetTextureAlphaMod(m_TextureCache[id], &a);
	SDL_RenderCopyEx(m_Renderer, m_TextureCache[id], nullptr, &Dst, 0, nullptr, SDL_FLIP_NONE);
}

void SDLGFX::DrawTexture(size_t id, const Color& color)
{
	Uint8 r = color.red;
	Uint8 g = color.green;
	Uint8 b = color.blue;
	Uint8 a = color.alpha;

	SDL_GetTextureColorMod(m_TextureCache[id], &r, &g, &b);
	SDL_GetTextureAlphaMod(m_TextureCache[id], &a);
	SDL_RenderCopyEx(m_Renderer, m_TextureCache[id], nullptr, nullptr, 0, nullptr, SDL_FLIP_NONE);
}

void SDLGFX::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t SDLGFX::LoadFont(const std::string& filename, int fontSize)
{
	/*TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
if (m_FontCache.count(fontId) > 0)
{
	TTF_Font* _font = m_FontCache[fontId];
	SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), _color);
	g_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
	SDL_RenderCopy(m_Renderer, g_TextureBuffer, nullptr, &_dst);
	SDL_FreeSurface(_surface);

}*/
	return size_t();
}

void SDLGFX::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{

}

void SDLGFX::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{

}
