#pragma once
#include <iostream>

#include "../Plant.hpp"
using namespace std;

class Grass : public Plant {
   public:
    Grass(int x, int y, World& worldRef) : Plant("Grass", 9, x, y, worldRef) {}

    void draw() override {
        cout << "🌱";
    }
};
