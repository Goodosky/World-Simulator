#pragma once
#include <iostream>

#include "Organism.hpp"

using namespace std;

class Plant : public Organism {
   public:
    Plant(string name, int power, int x, int y, World& worldRef);

    void action() override;

    void reproduce();
};
