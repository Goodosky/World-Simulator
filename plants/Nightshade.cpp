#include "../headers/plants/Nightshade.hpp"

#include "../headers/World.hpp"

Nightshade::Nightshade(int x, int y, World& worldRef) : Plant("Nightshade", 99, x, y, worldRef) {}

void Nightshade::draw() {
    cout << "🫐";
}

void Nightshade::collision(Organism* attacker) {
    // Attacker kills Nightshade
    cout << "💀 " << attacker->getName() << "(attacker) ate " << name << " at (" << x << ", " << y << ")" << endl;
    worldRef.removeOrganism(this);

    // but attacker also dies
    cout << "🎁 " << attacker->getName() << " ate Nightshade and died" << endl;
    worldRef.removeOrganism(attacker);
}