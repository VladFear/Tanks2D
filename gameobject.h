#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL.h>

class Window;

class GameObject
{
private:

private:
	bool init();

public:
	GameObject(Window* window);
	virtual ~GameObject();
	virtual void pollEvents(const SDL_Event& e) = 0;

protected:
	Window* _window = nullptr;
};

#endif // GAMEOBJECT_H
