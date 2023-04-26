#include "../headers/animals/Antelope.hpp"

#include "../headers/World.hpp"

Antelope::Antelope(int x, int y, World& worldRef) : Animal("Antelope", 4, 4, x, y, worldRef) {
    Animal::range = 2;
}

void Antelope::draw() {
    cout << "🦌";
}

void Antelope::fight(Organism* attacker) {
    int chance = rand() % 100;
    if (chance < 50) {
        Animal::fight(attacker);
        return;
    }

    // Run away
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y, range, false);

    if (x != new_x || y != new_y) {
        cout << "🎁 Antelope ran away!" << endl;
        move(new_x, new_y);
    } else {
        cout << "🎁 Antelope had nowhere to run! He has to fight now..." << endl;
        Animal::fight(attacker);
    }
}