#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

class TextureManager
{
public:
	static SDL_Texture* loadTexture(const std::string path);
	static void drawTexture(SDL_Texture *texture, const SDL_Rect& src, const SDL_Rect& dest);
};

#endif // TEXTUREMANAGER_H
