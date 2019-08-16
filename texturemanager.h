#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
	static SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
};

#endif // TEXTUREMANAGER_H
