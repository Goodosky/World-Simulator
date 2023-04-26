#include "headers/Plant.hpp"

#include "headers/World.hpp"

Plant::Plant(string name, int power, int x, int y, World& worldRef) : Organism(x, y, power, 0, name, worldRef) {}

void Plant::action() {
    reproduce();
};

void Plant::reproduce() {
    //  Draw position of new organism
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y, 1, false);

    // Add new organism to the world.
    if (x != new_x || y != new_y) {
        worldRef.addOrganism(name, new_x, new_y);
        cout << "💚 " << name << " has reproduced. Added " << name << " at (" << new_x << ", " << new_y << ")" << endl;
    } else {
        cout << "💔 " << name << " tried to reproduce, but there was no space around" << endl;
    }
}
