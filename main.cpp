#include <vector>
#include <string>

#include "window.h"
#include "tank.h"
#include "gameobject.h"
#include "map.h"
#include "texturemanager.h"

void pollEvents(const std::vector<GameObject*>& vec)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		for (auto element : vec)
			element->pollEvents(e);
	}
}

int main()
{
    Window window("Tanks2D", 800, 640);
    Map map;
    Tank tank(0, 0, 32, 48, "images/tank.png");

    std::string font_path = "../Tanks2D/font.ttf";
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), 30);
	if (nullptr == font)
		std::cerr << "Failed to open font!\n";

	// FPS
	SDL_Color textColor = {0, 255, 0, 255};
    SDL_Rect src;
    SDL_Rect dest;
    src.x = src.y = 0;
    src.w = dest.w = 35;
    src.h = dest.h = 35;
    dest.x = dest.y = 5;
	constexpr int FPS = 60;
	constexpr int frame_delay = 1000 / FPS;

	Uint32 frame_start = 0;
	int frame_time = 0;
	int frames = 0;

	std::vector<GameObject*> vec;
	vec.push_back(&window);
	vec.push_back(&tank);

	while (!window.isClosed())
	{
        window.clear();
		frame_start = SDL_GetTicks();

		pollEvents(vec);
		map.drawMap();
		tank.update();
		tank.draw();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time)
			SDL_Delay(frame_delay - frame_time);
		frames = 1000 / (SDL_GetTicks() - frame_start);
		TextureManager::drawTexture(TextureManager::loadTtfTexture(font, textColor, std::string(std::to_string(frames))), src, dest);
	}

	return 0;
}
