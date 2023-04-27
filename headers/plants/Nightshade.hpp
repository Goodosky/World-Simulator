#pragma once
#include <iostream>

#include "../Plant.hpp"
using namespace std;

class Nightshade : public Plant {
   public:
    Nightshade(int x, int y, World& worldRef);

    void draw() override;
    void collision(Organism* attacker) override;
};
