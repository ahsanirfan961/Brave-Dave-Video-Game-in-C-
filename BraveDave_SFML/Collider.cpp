#include "Collider.h"
#include <iostream>

using namespace sf;

sf::Vector2i Collider::operator^(Collider& c)
{
	return CheckCollision(c);
}

Vector2f Collider::getPosition(void) const
{
	return body->getPosition();
}

Vector2f Collider::getHalfSize(void) const
{
	IntRect temp = body->getTextureRect();
	return Vector2f((temp.width / 2.0f) * abs(body->getScale().x), (temp.height / 2.0f) * abs(body->getScale().y));
}

void Collider::Move(double dx, double dy)
{
	body->move(dx, dy);
}

Vector2i Collider::CheckCollision(Collider &body2)
{
	Vector2f position_body = getPosition();
	Vector2f position_body2 = body2.getPosition();
	Vector2f HalfSize_body = getHalfSize();
	Vector2f HalfSize_body2 = body2.getHalfSize();

	// std::cout << position_body2.x << ' ' << position_body2.y << std::endl;

	double deltaX = position_body.x - position_body2.x;
	double deltaY = position_body.y - position_body2.y;

	double intersectX = abs(deltaX) - (HalfSize_body.x + HalfSize_body2.x);
	double intersectY = abs(deltaY) - (HalfSize_body.y + HalfSize_body2.y);

	Vector2i face(0, 0);

	if (intersectX <= -5 && intersectY <= 0)
	{
		if ((abs(intersectY) >= body2.getHalfSize().y) && (position_body.x < position_body2.x))
			face.x = 2; // Collision from right = 2
		if ((abs(intersectY) >= body2.getHalfSize().y) && (position_body.x > position_body2.x))
			face.x = 4; // Collision from left = 4
		if (abs(intersectX) >= body2.getHalfSize().x/2 && (position_body.y < position_body2.y))
			face.y = 3; // Collision from bottom = 3
		if ((abs(intersectX) >= body2.getHalfSize().x) && (position_body.y > position_body2.y))
			face.y = 1; // Collision from top = 1

		return face;
	}

	else
		return face;
}
