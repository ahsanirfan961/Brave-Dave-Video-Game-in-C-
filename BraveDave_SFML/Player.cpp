#include "Player.h"
#include "Level.h"

Player::Player() : health(1), gun_equiped(false), jetpack_equipped(false), points(0), key_equipped(false), jet_on_off(false), jet_fuel(0) {}

Player::Player(unsigned int health, bool gun, bool jet, int n_anim) : health(health), gun_equiped(gun), jetpack_equipped(jet)
{
	points = 0;
	key_equipped = false;
	jet_on_off = false;
	jet_fuel = 0;
}

void Player::setHealth(unsigned int health)
{
	if (health <= 3)
		this->health = health;
}

void Player::setGunStatus(bool status)
{
	gun_equiped = status;
}

void Player::setJetEquipStatus(bool status)
{
	jetpack_equipped = status;
}

void Player::setJetWorkingStatus(bool status)
{
	jet_on_off = status;
}

void Player::setJetFuel(unsigned int fuel)
{
	if (fuel <= 100)
		jet_fuel = fuel;
}

void Player::setPoints(unsigned int points)
{
	this->points = points;
}

const unsigned int& Player::getHealth(void) const
{
	return health;
}

const unsigned int& Player::getJetFuel(void) const
{
	return jet_fuel;
}

const bool& Player::getGunStatus(void) const
{
	return gun_equiped;
}

const bool& Player::getJetEquipStatus(void) const
{
	return jetpack_equipped;
}

const bool& Player::getJetWorkingStatus(void) const
{
	return jet_on_off;
}

const unsigned int& Player::getPoints(void) const
{
	return points;
}

void Player::Jump(double totalTime)
{
	entity.move(0, -((2 - totalTime) * 6));
	if (totalTime >= 1)
		totalTime = 0;
}

void Player::shoot(bool& isShooting, const double& deltaTime, GameObject& bullet)
{
	static short int face_dir = 1;

	if (!isShooting) {
		isShooting = true;
		face_dir = getScale().x / abs(getScale().x);
		bullet.setScale(abs(bullet.getScale().x) * face_dir, bullet.getScale().y);
		bullet.setPosition(this->getPosition().x, this->getPosition().y);
	}
	else {
		if (bullet.getPosition().x > SCREEN_WIDTH + bullet.getSize().x + 100 || bullet.getPosition().x < -100 - bullet.getSize().x) {
			isShooting = false;
			return;
		}
		bullet.setPosition(bullet.getPosition().x + face_dir * deltaTime * 1000, bullet.getPosition().y);
	}

}

void Player::jetpack(double deltatime)
{
}