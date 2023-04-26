#pragma once
#include <iostream>

#include "Organism.hpp"

using namespace std;

class Animal : public Organism {
   protected:
    int range = 1;

   public:
    Animal(string name, int power, int initiative, int x, int y, World& worldRef);

    void collision(Organism* attacker) override;
    void action() override;

    virtual void move(int new_x, int new_y);
};
