#pragma once
#include <iostream>

#include "Organism.hpp"

using namespace std;

class Animal : public Organism {
   private:
   public:
    Animal(string name, int power, int initiative, int x, int y, World& worldRef);

    void collision(Organism* attacker) override;
    void action() override;
    void reproduce(Organism* attacker);
    void fight(Organism* attacker);
};
