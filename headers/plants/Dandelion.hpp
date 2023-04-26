#pragma once
#include <iostream>

#include "../Plant.hpp"
using namespace std;

class Dandelion : public Plant {
   public:
    Dandelion(int x, int y, World& worldRef) : Plant("Dandelion", 0, x, y, worldRef) {}

    void draw() override {
        cout << "🌼";
    }

    void action() override {
        for (int i = 0; i < 3; i++) {
            Plant::action();
        }
    }
};
