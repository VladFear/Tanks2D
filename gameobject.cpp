#include "gameobject.h"

bool GameObject::init()
{
	if (!_window)
		return false;

	return true;
}

GameObject::GameObject(Window* window) : _window(window)
{
	if (!init())
		std::cerr << "Error for initing GameObject!\n";
}

GameObject::~GameObject()
{

}
