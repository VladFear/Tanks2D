#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gameobject.h"

class Window : public GameObject
{
private:
	SDL_Window* sdl_window = nullptr;

	std::string _title;
	bool _closed = false;
	int _height = 640;
	int _width = 800;

private:
	void init();

public:
	static SDL_Renderer* _renderer;

public:
	explicit Window(const std::string& title, const int width, const int height);
	~Window();
	inline bool isClosed() const { return _closed; }
	void pollEvents(const SDL_Event& e) override;
	void clear() const;

};

#endif // WINDOW_H
