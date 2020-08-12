#include "pch.h"
#include "Texture.h"

bool NC::Texture::Create(const std::string& name, SDL_Renderer* renderer)
{
	SDL_Surface* surface = SDL_LoadBMP(name.c_str()); // loads sf2.bmp from Build
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
	SDL_FreeSurface(surface);

	return true;
}

void NC::Texture::Destroy()
{
	delete m_texture;
}

void NC::Texture::Draw(const Vector2& position, const Vector2& scale, float angle)
{
	Vector2 size = GetSize();

	SDL_Rect rect;
	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	SDL_RenderCopy(m_renderer, m_texture, NULL, SDL_FLIP_NONE);
}

NC::Vector2 NC::Texture::GetSize()
{
	int w, h;
	SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);

	return Vector2(w, h);
}
