#include "../headers/animals/Human.hpp"

#include "../headers/World.hpp"

Human::Human(int x, int y, World& worldRef) : Animal("Human", 5, 4, x, y, worldRef) {}

void Human::draw() {
    cout << "🥷";
}

void Human::action() {
    if (!direction) return;

    int new_x, new_y;

    switch (direction) {
        case 1:
            new_x = x;
            new_y = y - 1;
            break;
        case 2:
            new_x = x + 1;
            new_y = y;
            break;
        case 3:
            new_x = x;
            new_y = y + 1;
            break;
        case 4:
            new_x = x - 1;
            new_y = y;
            break;

        default:
            break;
    }

    if (new_x >= 0 && new_x < worldRef.getWidth() && new_y >= 0 && new_y < worldRef.getHeight()) {
        if (worldRef.getOrganism(new_x, new_y) != nullptr) {
            worldRef.getOrganism(new_x, new_y)->collision(this);
        } else {
            move(new_x, new_y);
        }
    } else {
        cout << "🥷 Human tried to move out of the world" << endl;
    }

    direction = 0;  // reset direction
}

void Human::updatePower() {
    if (specialAbilityCooldown > 0) {
        power = 5 + specialAbilityCooldown;
        specialAbilityCooldown--;
    }
}

void Human::activateSpecialAbilityCooldown() {
    specialAbilityCooldown = 5;
    cout << "\n\033[1;33mHuman special ability activated!\033[0m\n\n";
}

void Human::setDirection(int direction) {
    this->direction = direction;
}

int Human::getSpecialAbilityCooldown() {
    return specialAbilityCooldown;
}
