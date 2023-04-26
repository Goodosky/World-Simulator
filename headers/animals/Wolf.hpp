#pragma once
#include <iostream>

#include "../Animal.hpp"
using namespace std;

class Wolf : public Animal {
   public:
    Wolf(int x, int y, World& worldRef) : Animal("Wolf", 9, 5, x, y, worldRef) {}

    void draw() override {
        cout << "🐺";
    }
};
