#include <vector>

#include "window.h"
#include "tank.h"
#include "gameobject.h"

void pollEvents(std::vector<GameObject*>& vec)
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
	const int FPS = 60;
	const int frame_delay = 1000 / FPS;

	Uint32 frame_start = 0;
	int frame_time = 0;

	Window window("Test", 800, 640);
	Tank tank(&window, 0, 0, 50, 50, "images/tank.png");
	std::vector<GameObject*> vec;
	vec.push_back(&window);
	vec.push_back(&tank);

	while (!window.isClosed())
	{
		frame_start = SDL_GetTicks();

		pollEvents(vec);
		tank.update();
		tank.draw();
		window.clear();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time)
			SDL_Delay(frame_delay - frame_time);
	}

	return 0;
}
