#include "../headers/animals/Fox.hpp"

#include "../headers/World.hpp"

Fox::Fox(int x, int y, World& worldRef) : Animal("Fox", 3, 7, x, y, worldRef) {}

void Fox::draw() {
    cout << "🦊";
}

void Fox::action() {
    //  Draw a move direction
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y);

    Organism* organism = worldRef.getOrganism(new_x, new_y);

    if (organism == nullptr) {
        move(new_x, new_y);
    } else if (power >= organism->getPower()) {
        organism->collision(this);
    }

    cout << "🎁 Fox gave up attacking the stronger one" << endl;
};
