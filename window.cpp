#include "window.h"

int Window::init()
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError( ) << "\n";
		return 1;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	if (nullptr == _window )
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		return 2;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer)
	{
		std::cerr << "SDL could not initialize window! SDL Error: " << SDL_GetError( ) << "\n";
		return 3;
	}

	return 0;
}

Window::Window(std::string title, int width, int height)
	: _title(title), _width(width), _height(height)
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
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Window::pollEvents()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
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
}

void Window::clear() const
{
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	// Clear the entire screen to our selected color.
	SDL_RenderClear(_renderer);
	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
}
