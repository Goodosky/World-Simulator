#pragma once
#include <iostream>

#include "../Animal.hpp"
using namespace std;

class Sheep : public Animal {
   public:
    Sheep(int x, int y, World& worldRef) : Animal("Sheep", 4, 4, x, y, worldRef) {}

    void draw() override {
        cout << "🐑";
    }
};
