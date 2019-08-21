#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cmath>

#include "gameobject.h"
#include "window.h"
#include "texturemanager.h"

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
	const float SPEED = 1;
	const int ROTATION_SPEED = 2;

private:
	bool init();

public:
	Tank();
	Tank(int x, int y, int w, int h, std::string path);
	~Tank();
	inline void turn(const int a) { _angle += (a % 360); }
	void draw() const;
	void update();
	void pollEvents(const SDL_Event& e) override;
};

#endif // TANK_H
