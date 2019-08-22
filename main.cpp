#include <vector>

#include "window.h"
#include "tank.h"
#include "gameobject.h"
#include "map.h"

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
	constexpr int FPS = 60;
	constexpr int frame_delay = 1000 / FPS;

	Uint32 frame_start = 0;
	int frame_time = 0;

	Window window("Test", 800, 640);
	Map map();
//	Tank tank1(20, 20, 54, 72, "images/enemy.png");
	Tank tank(0, 0, 50, 50, "images/tank1.png");

	std::vector<GameObject*> vec;
	vec.push_back(&window);
	vec.push_back(&tank);
//	vec.push_back(&tank1);

	while (!window.isClosed())
	{
		frame_start = SDL_GetTicks();

		pollEvents(vec);
		map.drawMap();
		tank.update();
		tank.draw();
//		tank1.update();
//		tank1.draw();
		window.clear();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time)
			SDL_Delay(frame_delay - frame_time);
	}

	return 0;
}
