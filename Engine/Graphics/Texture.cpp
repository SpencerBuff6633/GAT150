#include "pch.h"
#include "Texture.h"
#include "Renderer.h"

bool NC::Texture::Create(const std::string& name, void* renderer)
{
	m_renderer = static_cast<Renderer*>(renderer)->m_renderer;

	SDL_Surface* surface = IMG_Load(name.c_str()); // loads sf2.bmp from Build
	if (surface == nullptr)
	{
		return false;
	}
	
	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		return false;
	}

	return true;
}

void NC::Texture::Destroy()
{
	SDL_DestroyTexture(m_texture);
}

void NC::Texture::Draw(const Vector2& position, const Vector2& scale, float angle)
{
	Vector2 size = GetSize();
	size = size * scale;
	SDL_Rect rect;
	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);

}

void NC::Texture::Draw(const SDL_Rect& source, const Vector2& position, const Vector2& scale, float angle)
{
	Vector2 size = { source.w , source.h };
	size *= scale;

	SDL_Rect rect;
	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	SDL_RenderCopyEx(m_renderer, m_texture, &source, &rect, angle, nullptr, SDL_FLIP_NONE);
}

NC::Vector2 NC::Texture::GetSize()
{
	int w, h;
	SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);

	return Vector2(w, h);
}
