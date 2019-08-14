#include "window.h"

int main()
{
	Window window("Test", 800, 600);

	while (!window.isClosed())
	{
		window.pollEvents();
		window.clear();
	}

	return 0;
}
