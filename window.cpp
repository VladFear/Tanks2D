#include "window.h"

SDL_Renderer* Window::_renderer = nullptr;

int Window::init()
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError( ) << "\n";
		return 1;
	}

	sdl_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	if (nullptr == sdl_window)
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		return 2;
	}

	_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer)
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		return 3;
	}

	return 0;
}

Window::Window(std::string title, int width, int height)
	: GameObject(), _title(title), _height(height), _width(width)
{
	if (0 != init())
	{
		std::cout << "Could not init SDL window!" << std::endl;
		_closed = true;
	}

	_closed = false;
}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}

void Window::pollEvents(const SDL_Event &e)
{
	switch(e.type)
	{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				_closed = true;
				break;

			default:
				break;
		}

		default:
			break;
	}
}

void Window::clear() const
{
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}
