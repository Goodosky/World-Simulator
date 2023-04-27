#pragma once
#include <iostream>

#include "../Plant.hpp"
using namespace std;

class Guarana : public Plant {
   public:
    Guarana(int x, int y, World& worldRef);

    void draw() override;
    void collision(Organism* attacker) override;
};
