#include "texturemanager.h"

SDL_Texture *TextureManager::loadTexture(const std::string& path)
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

SDL_Texture *TextureManager::loadTtfTexture(const TTF_Font *font, const SDL_Color &textColor, const std::string &text)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(const_cast<TTF_Font*>(font), text.c_str(), textColor);
    if (nullptr == textSurface)
        std::cerr << "Failed to create textSurface!" << SDL_GetError() << "\n";

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::_renderer, textSurface);
    if (nullptr == texture)
        std::cerr << "Failed to create texture from textSurface!" << SDL_GetError() << "\n";

    SDL_FreeSurface(textSurface);

    return texture;
}

void TextureManager::drawTexture(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest)
{
	SDL_RenderCopy(Window::_renderer, texture, &src, &dest);
}
