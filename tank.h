#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cmath>
#include <vector>

#include "gameobject.h"
#include "window.h"
#include "texturemanager.h"

#define DEBUG 0

class Tank : public GameObject
{
private:
	enum class Direction : int
	{
		FORWARD = 1,
		BACKWARD = -1
	};

	SDL_Texture* _texture = nullptr;
    std::vector<SDL_Point> points;
	double dx = 0;
	double dy = 0;
	int _height = 0;
	int _width = 0;
	double _angle = 0;
	Direction direction = Direction::FORWARD;
	bool riding = false;
	const float SPEED = 1;
	const int ROTATION_SPEED = 2;

public:
	explicit Tank();
	Tank(const int x, const int y, const int w, const int h, const std::string& path);
	~Tank();
	inline void turn(const int a) { _angle += (a % 360); }
	void draw() const;
	void update();
	void pollEvents(const SDL_Event& e) override;
};

#endif // TANK_H
