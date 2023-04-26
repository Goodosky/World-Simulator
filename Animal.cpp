#include "headers/Animal.hpp"

#include "headers/World.hpp"

Animal::Animal(string name, int power, int initiative, int x, int y, World& worldRef) : Organism(x, y, power, initiative, name, worldRef) {}

void Animal::collision(Organism* attacker) {
    if (attacker->getName() == name) {
        // if collision is with the same species, try to reproduce (only if both are older than 6)
        if (attacker->getAge() > 6 && age > 6) reproduce();
    } else {
        fight(attacker);
    }
};

void Animal::action() {
    //  Draw a move direction
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y, range);

    if (worldRef.getOrganism(new_x, new_y) != nullptr) {
        worldRef.getOrganism(new_x, new_y)->collision(this);
    } else {
        move(new_x, new_y);
    }
};

void Animal::move(int new_x, int new_y) {
    cout << "🐾 " << name << " moves from (" << x << ", " << y << ") to (" << new_x << ", " << new_y << ")" << endl;
    worldRef.moveOrganism(this, new_x, new_y);
}
