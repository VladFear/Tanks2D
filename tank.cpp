#include "tank.h"

Tank::Tank() : GameObject()
{

}

Tank::Tank(const int x, const int y, const int w, const int h, const std::string &_path)
	: _x(x), _y(y), _height(h), _width(w)
{
	std::string path = "../Tanks2D/" + _path;
	_texture = TextureManager::loadTexture(path);

	if (!_texture)
		std::cerr << "Failed to load tank texture!\n";
}

Tank::~Tank()
{
	SDL_DestroyTexture(_texture);
}

void Tank::draw() const
{
	if (!_texture)
		return;

	SDL_Rect rect = { static_cast<int>(_x), static_cast<int>(_y), _width, _height };
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RenderCopyEx(Window::_renderer, _texture, nullptr, &rect, _angle + 90.0, nullptr, flip);
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
					direction = Direction::FORWARD;
					break;
				case SDLK_s:
					riding = true;
					direction = Direction::BACKWARD;
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

	_x += dx * static_cast<int>(direction);
	_y += dy * static_cast<int>(direction);
}
