#pragma once
#include <memory>
#include "GameObject.h"
#include "Animation.h"
#include "Gravity.h"
#include <vector>

class DynamicObject : public GameObject
{

private:
    double speed;
    unsigned int n_animation;

public:
    std::vector<Animation> animation;
    Gravity gravity;

public:
    DynamicObject();
    DynamicObject(const GameObject &a, double speed, const unsigned int n_anim, std::vector<Animation> anim);
    DynamicObject(const DynamicObject &a);
    void setSpeed(double speed);
    void setNumOfAnimation(int n);
    const double& getSpeed(void) const;
    void updatePosition(double x, double y);
};
