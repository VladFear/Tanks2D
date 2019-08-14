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
	Window window("Test", 800, 600);
	Tank tank(&window, 0, 0, 50, 50, "images/tank.png");
	std::vector<GameObject*> vec;
	vec.push_back(&window);
	vec.push_back(&tank);

	while (!window.isClosed())
	{
		pollEvents(vec);
		tank.update();
		tank.draw();
		window.clear();
	}

	return 0;
}
