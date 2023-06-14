#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
using namespace sf;

class GameObject
{
public:
	Collider collider;
	Texture texture;

protected:
	Sprite entity;
	Color colour;

public:
	GameObject();
	GameObject(const Sprite &a, const Texture &b, const Color &c) : entity(a), texture(b), colour(c), collider(&entity) {}
	GameObject(double pos_x, double pos_y, double scale, String texture_path, IntRect TextureRect);
	void setPosition(double x, double y);
	void setOrigin(double x, double y);
	virtual void setTexture(String path);
	void setTexture(Texture &);
	void setTextureSource(double x, double y, double width, double height);
	void setTextureSource(IntRect a);
	void setTextureSource_xInvert(IntRect a);
	void setScale(double x, double y);
	void setColour(int opacity, int blue, int green, int red);
	void setTextureRepitition(bool);
	const Vector2f& getPosition() const;
	const Vector2f& getOrigin() const;
	const Vector2f& getSize() const;
	const Vector2f& getScale() const;
	const IntRect& getTextureRect() const;
	void Draw(RenderWindow &window);
};
