#pragma once
#include <iostream>

#include "../Animal.hpp"
using namespace std;

class Turtle : public Animal {
   public:
    Turtle(int x, int y, World& worldRef) : Animal("Turtle", 2, 1, x, y, worldRef) {}

    void draw() override {
        cout << "🐢";
    }

    void action() override {
        int chance = rand() % 100;
        if (chance > 75) {
            Animal::action();
        }
    }

    void fight(Organism* attacker) override {
        if (attacker->getPower() >= 5) {
            Animal::fight(attacker);
        }
    }
};
