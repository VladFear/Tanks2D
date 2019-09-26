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

    auto top_left = std::make_pair(x, y);
    auto top_right = std::make_pair(x + _width, y);
    auto bot_right = std::make_pair(x + _width, y + _height);
    auto bot_left = std::make_pair(x, y + _height);
    points.push_back(top_left);
    points.push_back(top_right);
    points.push_back(bot_right);
    points.push_back(bot_left);
	center = std::make_pair((points[0].first + points[2].first) / 2.0, (points[0].second + points[2].second) / 2.0);
}

Tank::~Tank()
{
	SDL_DestroyTexture(_texture);
}

void Tank::turn(const int a)
{
	if (_angle > 360)
		_angle -= 360;

	_angle += a;
	radians = _angle * M_PI / 180.0;

	center = std::make_pair((points[0].first + points[2].first) / 2.0, (points[0].second + points[2].second) / 2.0);

	for (auto& p : points)
	{
		p.first -= center.first;
		p.second -= center.second;

		p.first = p.first * std::cos(radians) - p.second * std::sin(radians);
		p.second = p.first * std::sin(radians) + p.second * std::cos(radians);

		p.first += center.first;
		p.second += center.second;
	}
}

void Tank::draw() const
{
	if (!_texture) return;

	SDL_Rect rect;
	rect.x = static_cast<int>(points[0].first);
	rect.y = static_cast<int>(points[0].second);
	rect.w = _width;
	rect.h = _height;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
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
//	radians = (_angle - 90) * M_PI / 180.0;

//	if (riding)
//	{
//		dx = std::cos(radians) * SPEED;
//		dy = std::sin(radians) * SPEED;
//	}
//	else
//	{
//		dx *= 0.93;
//		dy *= 0.93;
//	}

//	points[0].first += dx * static_cast<int>(direction);
//	points[0].second += dy * static_cast<int>(direction);

#ifdef DEBUG
	std::cout << radians << std::endl;
	std::cout << "1) " << points[0].first << " : " << points[0].second << std::endl;
	std::cout << "2) " << points[1].first << " : " << points[1].second << std::endl;
	std::cout << "3) " << points[2].first << " : " << points[2].second << std::endl;
	std::cout << "4) " << points[3].first << " : " << points[3].second << std::endl;
	std::cout << "center x: " << center.first << " y: " << center.second << std::endl;
#endif
}
