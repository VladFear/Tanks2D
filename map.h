#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

#include "window.h"
#include "texturemanager.h"

class Map
{
private:
	int tiles[20][25];
	SDL_Texture* wall = nullptr;
	SDL_Rect src;
	SDL_Rect dest;

public:
	Map();
	void loadMap(int lvl[20][25]);
	void drawMap();
};

#endif // MAP_H
