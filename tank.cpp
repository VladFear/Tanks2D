#include "tank.h"

Tank::Tank() : GameObject()
{

}

Tank::Tank(const int x, const int y, const int w, const int h, const std::string &_path)
    : _height(h), _width(w)
{
	std::string path = "../Tanks2D/" + _path;
	_texture = TextureManager::loadTexture(path);

	if (!_texture)
        std::cerr << "Failed to load tank texture!\n";

    SDL_Point top_left { x, y };
    SDL_Point top_right { x + _width, y };
    SDL_Point bot_right { x + _width, y + _height };
    SDL_Point bot_left { x, y + _height };
    points.push_back(top_left);
    points.push_back(top_right);
    points.push_back(bot_right);
    points.push_back(bot_left);
}

Tank::~Tank()
{
	SDL_DestroyTexture(_texture);
}

void Tank::draw() const
{
	if (!_texture)
		return;

    SDL_Rect rect = { static_cast<int>(points[0].x), static_cast<int>(points[0].y), _width, _height };
    SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
    SDL_RenderCopyEx(Window::_renderer, _texture, nullptr, &rect, _angle, nullptr, flip);
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
    const double radians = (_angle + 90) * M_PI / 180.0;

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

    points[0].x += dx * static_cast<int>(direction);
    points[0].y += dy * static_cast<int>(direction);

#ifdef DEBUG
    std::cout << "1) " << points[0].x << " : " << points[0].y << std::endl;
    std::cout << "2) " << points[1].x << " : " << points[1].y << std::endl;
    std::cout << "3) " << points[2].x << " : " << points[2].y << std::endl;
    std::cout << "4) " << points[3].x << " : " << points[3].y << std::endl;
#endif
}
