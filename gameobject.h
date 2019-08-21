#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL.h>

class Window;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void pollEvents(const SDL_Event& e) = 0;
};

#endif // GAMEOBJECT_H
