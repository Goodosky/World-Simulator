#include "Animal.hpp"

#include "World.hpp"

Animal::Animal(string name, int power, int initiative, int x, int y, World& worldRef) : Organism(x, y, power, initiative, name, worldRef) {}

void Animal::collision(Organism* attacker) {
    // if collision is with the same species, create a new organism
    if (attacker->getName() == name) {
        int new_x = x;
        int new_y = y;
        worldRef.getRandomNeighborPosition(new_x, new_y, false);
        worldRef.addOrganism(name, new_x, new_y);
        cout << "💛 " << name << " has reproduced. Added " << name << " at (" << new_x << ", " << new_y << ")" << endl;
        return;
    }

    // if collision is with a weaker organism, eat it
    if (attacker->getPower() < power) {
        cout << "💀 " << name << " ate " << attacker->getName() << endl;
        worldRef.removeOrganism(attacker);
        return;
    }
};

void Animal::action() {
    //  Draw a move direction
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y);

    if (worldRef.getOrganism(new_x, new_y) != nullptr) {
        worldRef.getOrganism(new_x, new_y)->collision(this);
    } else {
        cout << "🐾 " << name << " moves from (" << x << ", " << y << ") to (" << new_x << ", " << new_y << ")" << endl;
        worldRef.moveOrganism(this, new_x, new_y);
    }

    this->setPosition(new_x, new_y);
};