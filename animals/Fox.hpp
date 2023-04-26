#pragma once
#include <iostream>

#include "../Animal.hpp"
#include "../World.hpp"

using namespace std;

class Fox : public Animal {
   public:
    Fox(int x, int y, World& worldRef);

    void draw() override;

    void action() override;
};
