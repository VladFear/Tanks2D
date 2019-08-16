#include "texturemanager.h"

SDL_Texture *TextureManager::loadTexture(std::string path, SDL_Renderer *renderer)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface)
		std::cerr << "Failed to create surface!\n";

	SDL_Texture* _texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!_texture)
		std::cerr << "Failed to create texture from surface!\n";

	SDL_FreeSurface(surface);
	return _texture;
}
