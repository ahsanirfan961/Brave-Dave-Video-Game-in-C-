#include "Gravity.h"

Gravity::Gravity(Sprite &object, double g) : object(object), gravitationalAcceleration(g), time(0)
{
}

void Gravity::setGravity(double deltatime, bool freefall)
{
	time += deltatime;
	static double speed = 0;
	if (speed <= 5)
		speed += gravitationalAcceleration * time;
	if (freefall)
		object.move(0, speed);
	else
	{
		time = 0;
		speed = 0;
	}
}

void Gravity::setGravitionalAcceleration(double g)
{
	gravitationalAcceleration = g;
}