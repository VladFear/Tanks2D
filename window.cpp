#include "window.h"

SDL_Renderer* Window::_renderer = nullptr;

void Window::init()
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError( ) << "\n";
		exit(EXIT_FAILURE);
	}

	sdl_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	if (nullptr == sdl_window)
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		exit(EXIT_FAILURE);
	}

	_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer)
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		exit(EXIT_FAILURE);
	}

	if (IMG_INIT_PNG != IMG_Init(IMG_INIT_PNG))
	{
		std::cerr << "Failed to load image library!\n";
		exit(EXIT_FAILURE);
	}
}

Window::Window(const std::string &title, const int width, const int height)
	: GameObject(), _title(title), _height(height), _width(width)
{
	init();
}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(sdl_window);
	IMG_Quit();
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
