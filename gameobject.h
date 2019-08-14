#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL.h>

#include "window.h"

class GameObject
{
private:
	SDL_Window* _window = nullptr;

private:
	bool init();

public:
	GameObject(SDL_Window* window);
	~GameObject();

protected:
};

#endif // GAMEOBJECT_H
