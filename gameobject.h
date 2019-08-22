#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>

class Window;

class GameObject
{
public:
	explicit GameObject();
	virtual ~GameObject();
	virtual void pollEvents(const SDL_Event& e) = 0;
};

#endif // GAMEOBJECT_H
