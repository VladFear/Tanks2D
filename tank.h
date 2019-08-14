#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <math.h>

#include "gameobject.h"
#include "window.h"

class Tank : public GameObject
{
private:
	SDL_Texture* _texture = nullptr;
	double _x = 0;
	double _y = 0;
	double dx = 0;
	double dy = 0;
	int _height = 0;
	int _width = 0;
	double _angle = 0;
	int forward = 1;
	bool riding = false;
	const float SPEED = 0.1;
	const int ROTATION_SPEED = 4;

private:
	bool init();

public:
	Tank(Window* window);
	Tank(Window* window, int x, int y, int w, int h, std::string path);
	~Tank();
	void draw() const;
	void pollEvents(const SDL_Event& e) override;
	void turn(const int a);
	void update();
};

#endif // TANK_H
