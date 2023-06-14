#include "Animation.h"

Animation::Animation(void)
{
	speed = 0;
	n_images = 0;
	width = 0;
	deltatime = 0;
	sound.setBuffer(buffer);
}

Animation::Animation(double speed, sf::Texture &texture, int n)
{
	this->speed = speed;
	sf::Vector2u temp = texture.getSize();
	width = double(temp.x / n);
	n_images = n;
	deltatime = 0;
	sound.setBuffer(buffer);
}

sf::IntRect Animation::update(double deltatime, sf::IntRect tex_size)
{

	this->deltatime += deltatime;
	if (this->deltatime >= 1 / speed)
	{
		this->deltatime = 0;
		tex_size.left += width;
		if (int(tex_size.left / width) % 2 == 0)
			sound.play();
	}
	if (tex_size.left == width * n_images)
		tex_size.left = width;
	return tex_size;
}

void Animation::setSpeed(double speed)
{
	this->speed = speed;
}

void Animation::set_n_images(int n)
{
	n_images = n;
}

void Animation::setWidth(std::string texturePath)
{
	sf::Texture t;
	t.loadFromFile(texturePath);
	sf::Vector2u temp = t.getSize();
	width = double(temp.x / n_images);
}

const double& Animation::getSpeed(void) const
{
	return speed;
}

const double& Animation::getWidth(void) const
{
	return width;
}

void Animation::setSound(std::string path)
{
	if (!buffer.loadFromFile(path))
		std::cout << "Walk sound load error" << std::endl;
	sound.setBuffer(buffer);
}