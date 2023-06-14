#pragma once
#include "DynamicObject.h"
class Player : public DynamicObject
{
private:
    unsigned int health;
    bool gun_equiped : 1;
    bool jetpack_equipped : 1;
    bool jet_on_off : 1;
    bool key_equipped : 1;
    unsigned int jet_fuel;
    unsigned int points;

public:
    using GameObject::entity;
    using GameObject::texture;

public:
    Player();
    Player(unsigned int health, bool gun, bool jet, int n_anim);
    void setHealth(unsigned int health);
    void setGunStatus(bool status);
    void setJetEquipStatus(bool status);
    void setJetWorkingStatus(bool status);
    void setJetFuel(unsigned int fuel);
    void setPoints(unsigned int points);
    const unsigned int& getHealth(void) const;
    const unsigned int& getPoints(void) const;
    const bool& getGunStatus(void) const;
    const bool& getJetEquipStatus(void) const;
    const bool& getJetWorkingStatus(void) const;
    const unsigned int& getJetFuel(void) const;
    void Jump(double totaltime);
    void shoot(bool& isShooting, const double& deltaTime, GameObject& bullet);
    void jetpack(double deltaTime);
};
