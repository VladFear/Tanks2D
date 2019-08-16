#include "tank.h"

bool Tank::init()
{
	if (IMG_INIT_PNG != IMG_Init(IMG_INIT_PNG))
	{
		std::cerr << "Failed to load image library!\n";
		return false;
	}

	return true;
}

Tank::Tank(Window *window) : GameObject(window)
{

}

Tank::Tank(Window *window, int x, int y, int w, int h, std::string _path)
	: GameObject(window), _x(x), _y(y), _height(h), _width(w)
{
	if (init())
	{
		std::string path = "../Tanks2D/" + _path;
		_texture = TextureManager::loadTexture(path, window->getRenderer());
	}
}

Tank::~Tank()
{
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

void Tank::draw() const
{
	if (!_texture)
		return;

	SDL_Rect rect = { static_cast<int>(_x), static_cast<int>(_y), _width, _height };
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RenderCopyEx(_window->getRenderer(), _texture, nullptr, &rect, _angle + 90.0, nullptr, flip);
}

void Tank::pollEvents(const SDL_Event& e)
{
	switch(e.type)
	{
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_w:
					riding = true;
					forward = 1;
					break;
				case SDLK_s:
					riding = true;
					forward = -1;
					break;
				case SDLK_a:
					turn(-ROTATION_SPEED);
					break;
				case SDLK_d:
					turn(ROTATION_SPEED);
					break;

				default:
					break;
			}
			break;

		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
				case SDLK_w:
				case SDLK_s:
					riding = false;
					break;

				default:
					break;
			}
			break;

		default:
			break;
	}
}

void Tank::update()
{
	const double radians = _angle * M_PI / 180.0;

	if (riding)
	{
		dx = std::cos(radians) * SPEED;
		dy = std::sin(radians) * SPEED;
	}
	else
	{
		dx *= 0.93;
		dy *= 0.93;
	}

	_x += dx * forward;
	_y += dy * forward;
}
