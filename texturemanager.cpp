#include "texturemanager.h"

SDL_Texture *TextureManager::loadTexture(const std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface)
		std::cerr << "Failed to create surface!\n";

	SDL_Texture* _texture = SDL_CreateTextureFromSurface(Window::_renderer, surface);
	if (!_texture)
		std::cerr << "Failed to create texture from surface!\n";

	SDL_FreeSurface(surface);
	return _texture;
}

void TextureManager::drawTexture(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest)
{
	SDL_RenderCopy(Window::_renderer, texture, &src, &dest);
}
