#include "GameObject.h"

GameObject::GameObject() : collider(&entity)
{
	entity.setPosition(Vector2f(0, 0));
	entity.setScale(Vector2f(1, 1));
}

GameObject::GameObject(double pos_x, double pos_y, double scale, String texture_path, IntRect TextureRect) : collider(&entity)
{
	entity.setPosition(Vector2f(pos_x, pos_y));
	entity.setScale(Vector2f(scale, scale));
	texture.loadFromFile(texture_path);
	entity.setTexture(texture);
	entity.setTextureRect(TextureRect);
}

void GameObject::setTextureSource_xInvert(IntRect a)
{
	entity.setTextureRect(IntRect(a.left, a.top, -abs(a.width), a.height));
}

void GameObject::setScale(double x, double y)
{
	entity.setScale(x, y);
}

void GameObject::setPosition(double x, double y)
{
	entity.setPosition(Vector2f(x, y));
}

void GameObject::setOrigin(double x, double y)
{
	entity.setOrigin(Vector2f(x, y));
}

void GameObject::setColour(int opacity, int blue, int green, int red)
{
	colour.a = opacity;
	colour.b = blue;
	colour.g = green;
	colour.r = red;
}

void GameObject::setTextureRepitition(bool isRepeated)
{
	texture.setRepeated(isRepeated);
}

void GameObject::setTexture(String path)
{
	texture.loadFromFile(path);
	entity.setTexture(texture);
}

void GameObject::setTextureSource(double x, double y, double width, double height)
{
	entity.setTextureRect(IntRect(x, y, width, height));
}

const Vector2f& GameObject::getPosition() const
{
	return entity.getPosition();
}

const Vector2f& GameObject::getOrigin() const
{
	return entity.getOrigin();
}

const IntRect& GameObject::getTextureRect() const
{
	return entity.getTextureRect();
}

const Vector2f& GameObject::getScale() const
{
	return entity.getScale();
}

void GameObject::Draw(RenderWindow &window)
{
	window.draw(entity);
}

void GameObject::setTextureSource(IntRect a)
{
	entity.setTextureRect(IntRect(a.left, a.top, abs(a.width), abs(a.height)));
}

const Vector2f& GameObject::getSize() const
{
	IntRect source = entity.getTextureRect();
	Vector2f scale = entity.getScale();

	return Vector2f(source.width * scale.x, source.height * scale.y);
}

void GameObject::setTexture(Texture &a)
{
	texture = a;
}