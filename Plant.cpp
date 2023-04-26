#include "headers/Plant.hpp"

#include "headers/World.hpp"

Plant::Plant(string name, int power, int x, int y, World& worldRef) : Organism(x, y, power, 0, name, worldRef) {}

void Plant::action() {
    int chance = rand() % 100;
    if (chance < PLANT_REPRODUCTION_CHANCE) {
        reproduce();
    }
};

void Plant::collision(Organism* attacker) {
    if (attacker->getPower() >= power) {
        // Attacker kills defender
        cout << "💀 " << attacker->getName() << "(attacker) ate " << name << " at (" << x << ", " << y << ")" << endl;
        worldRef.removeOrganism(this);
        worldRef.moveOrganism(attacker, x, y);
    } else {
        // Defender kills attacker
        cout << "💀 " << name << " (defender) ate " << attacker->getName() << " at (" << x << ", " << y << ")" << endl;
        worldRef.removeOrganism(attacker);
    }
}
