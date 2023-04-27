#include "../headers/plants/PineBorscht.hpp"

#include "../headers/World.hpp"

PineBorscht::PineBorscht(int x, int y, World& worldRef) : Plant("PineBorscht", 10, x, y, worldRef) {}

void PineBorscht::draw() {
    cout << "🌾";
}

void PineBorscht::action() {
    Plant::action();

    // PineBorscht also kills all organisms in its vicinity
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            // Skip out of bounds or self
            if (i < 0 || i >= worldRef.getWidth() || j < 0 || j >= worldRef.getHeight() || i == x && j == y) {
                continue;
            }

            Organism* organism = worldRef.getOrganism(i, j);
            if (organism != nullptr) {
                cout << "💀 " << name << " killed " << organism->getName() << " at (" << i << ", " << j << ")" << endl;
                worldRef.removeOrganism(organism);
            }
        }
    }
}
void PineBorscht::collision(Organism* attacker) {
    // Attacker kills PineBorscht
    cout << "💀 " << attacker->getName() << "(attacker) ate " << name << " at (" << x << ", " << y << ")" << endl;
    worldRef.removeOrganism(this);

    // but attacker also dies
    cout << "🎁 " << attacker->getName() << " ate PineBorscht and died" << endl;
    worldRef.removeOrganism(attacker);
}