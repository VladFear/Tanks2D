#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

#include "window.h"
#include "texturemanager.h"

class Map
{
private:
	enum class Texture : int
	{
		GROUND = 0,
		WALL = 1
	};

	static const int COLUMNS = 25;
	static const int ROWS = 20;
	int tiles[ROWS][COLUMNS];
	SDL_Texture* wall = nullptr;
	SDL_Texture* ground = nullptr;
	SDL_Rect src;
	SDL_Rect dest;

public:
	explicit Map();
	~Map();
	void loadMap(const int lvl[ROWS][COLUMNS]);
	void drawMap();
};

#endif // MAP_H
