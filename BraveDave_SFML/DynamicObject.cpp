#include "DynamicObject.h"

DynamicObject::DynamicObject() : n_animation(0), gravity(Gravity(entity, 9.8))
{
	speed = 0;
}

DynamicObject::DynamicObject(const GameObject &a, double speed, const unsigned int n_anim, std::vector<Animation> anim) : GameObject(a), speed(speed), n_animation(n_anim), gravity(Gravity(entity, 9.8))
{
	for (int i = 0; i < n_animation; i++)
		animation.push_back(anim[i]);
}

DynamicObject::DynamicObject(const DynamicObject &a) : GameObject(a.entity, a.texture, a.colour), n_animation(a.n_animation), gravity(a.gravity)
{
	this->speed = a.speed;
	for (int i = 0; i < n_animation; i++)
		this->animation[i] = a.animation[i];
}

void DynamicObject::setSpeed(double speed)
{
	this->speed = speed;
}

void DynamicObject::setNumOfAnimation(int n)
{
	n_animation = n;
	Animation a;
	int animationSize = animation.size();
	if (n > animationSize)
	{
		for (int i = 0; i < (n - animationSize); i++)
			animation.push_back(a);
	}
	if (n < animationSize)
	{
		for (int i = 0; i < (-n + animationSize); i++)
			animation.pop_back();
	}
}
const double& DynamicObject::getSpeed(void) const
{
	return speed;
}

void DynamicObject::updatePosition(double x, double y)
{
	Vector2f position = getPosition();
	setPosition(position.x + x, position.y + y);
}

