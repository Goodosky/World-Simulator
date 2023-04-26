#pragma once
#include <iostream>

#include "Organism.hpp"

using namespace std;

class Animal : public Organism {
   public:
    Animal(string name, int power, int initiative, int x, int y, World& worldRef);

    void collision(Organism* attacker) override;
    void action() override;

    virtual void move(int new_x, int new_y);
    virtual void reproduce(Organism* attacker);
    virtual void fight(Organism* attacker);
};
