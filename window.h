#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

#include "gameobject.h"

class Window : public GameObject
{
private:
	SDL_Window* sdl_window = nullptr;

	std::string _title;
	bool _closed = true;
	int _height = 640;
	int _width = 800;

private:
	int init();

public:
	static SDL_Renderer* _renderer;

public:
	Window(std::string title, int width, int height);
	~Window();
	inline bool isClosed() { return _closed; }
	void pollEvents(const SDL_Event& e) override;
	void clear() const;

};

#endif // WINDOW_H
