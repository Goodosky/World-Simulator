#pragma once
#include <iostream>

#include "../Animal.hpp"
using namespace std;

class Human : public Animal {
   private:
    int direction = 0;
    int specialAbilityCooldown = 0;

   public:
    Human(int x, int y, World& worldRef);

    void draw() override;
    void action() override;

    void updatePower();
    void activateSpecialAbilityCooldown();
    void setDirection(int direction);
    int getSpecialAbilityCooldown();
};
