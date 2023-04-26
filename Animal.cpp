#include "Animal.hpp"

#include "World.hpp"

Animal::Animal(string name, int power, int initiative, int x, int y, World& worldRef) : Organism(x, y, power, initiative, name, worldRef) {}

void Animal::collision(Organism* attacker) {
    cout << "!!! " << name << "( " << x << ", " << y << ") collides with " << attacker->getName() << " (" << attacker->getX() << ", " << attacker->getY() << ")" << endl;

    if (attacker->getName() == name) {
        // if collision is with the same species, try to reproduce
        reproduce(attacker);
    } else {
        fight(attacker);
    }
};

void Animal::action() {
    cout << "Do action: " << name << " (" << x << ", " << y << ")\n";

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
};

void Animal::reproduce(Organism* attacker) {
    // Animal can reproduce only if it is older than 6
    if (attacker->getAge() <= 6 && age <= 6) return;

    //  Draw position of new organism
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y, false);

    // Add new organism to the world.
    if (x != new_x || y != new_y) {
        worldRef.addOrganism(name, new_x, new_y);
        cout << "💞 " << name << " has reproduced. Added " << name << " at (" << new_x << ", " << new_y << ")" << endl;
    } else {
        cout << "💔 " << name << " tried to reproduce, but there was no space around" << endl;
    }
}

void Animal::fight(Organism* attacker) {
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