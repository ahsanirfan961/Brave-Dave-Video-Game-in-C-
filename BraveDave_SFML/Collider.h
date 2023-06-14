#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Collider
{
	friend class GameObject;
private:
	sf::Sprite *body;

	Collider(sf::Sprite *body) : body(body) {}
public:

	sf::Vector2i operator^(Collider&);

	sf::Vector2f getPosition(void) const;
	sf::Vector2f getHalfSize(void) const;
	sf::Vector2i CheckCollision(Collider &);
	void Move(double dx, double dy);
};
