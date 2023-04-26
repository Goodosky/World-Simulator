#pragma once
#include <iostream>

#include "../Animal.hpp"
using namespace std;

class Antelope : public Animal {
   public:
    Antelope(int x, int y, World& worldRef);

    void draw() override;

    void fight(Organism* attacker) override;
};
