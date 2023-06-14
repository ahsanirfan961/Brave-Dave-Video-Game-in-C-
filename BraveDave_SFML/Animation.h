#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Animation
{
private:
	double speed;
	int n_images;
	double width;
	double deltatime;
	sf::SoundBuffer buffer;

public:
	sf::Sound sound;
	Animation();
	Animation(double speed, sf::Texture &texture, int n);
	sf::IntRect update(double deltatime, sf::IntRect);
	void setSpeed(double);
	void set_n_images(int);
	void setWidth(std::string texturePath);
	void setSound(std::string path);
	const double& getSpeed(void) const;
	const double& getWidth(void) const;
};
