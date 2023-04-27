#pragma once
#include <iostream>

#include "../Plant.hpp"
using namespace std;

class PineBorscht : public Plant {
   public:
    PineBorscht(int x, int y, World& worldRef);

    void draw() override;
    void action() override;
    void collision(Organism* attacker) override;
};
