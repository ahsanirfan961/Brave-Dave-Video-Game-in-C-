#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Gravity
{
	friend class DynamicObject;
private:
	Sprite &object;
	double gravitationalAcceleration;
	double time;

	Gravity(Sprite &object, double g);
public:
	void setGravity(double deltatime, bool freefall);
	void setGravitionalAcceleration(double);
};
