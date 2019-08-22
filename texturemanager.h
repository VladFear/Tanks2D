#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"

class TextureManager
{
public:
	static SDL_Texture* loadTexture(const std::string& path);
    static SDL_Texture* loadTtfTexture(const TTF_Font* font, const SDL_Color& textColor, const std::string& text);
	static void drawTexture(SDL_Texture *texture, const SDL_Rect& src, const SDL_Rect& dest);
};

#endif // TEXTUREMANAGER_H
