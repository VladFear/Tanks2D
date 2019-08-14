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
	SDL_Renderer* _renderer = nullptr;

	std::string _title;
	bool _closed = true;
	int _height = 600;
	int _width = 800;

private:
	int init();

public:
	Window(std::string title, int width, int height);
	~Window();
	inline bool isClosed() { return _closed; }
	inline SDL_Renderer* getRenderer() const { return _renderer; }
	void pollEvents(const SDL_Event& e) override;
	void clear() const;
};

#endif // WINDOW_H
