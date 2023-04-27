#include "../headers/plants/Guarana.hpp"

#include "../headers/World.hpp"

Guarana::Guarana(int x, int y, World& worldRef) : Plant("Guarana", 0, x, y, worldRef) {}

void Guarana::draw() {
    cout << "🍇";
}

void Guarana::collision(Organism* attacker) {
    // Attacker kills Guarana
    cout << "💀 " << attacker->getName() << "(attacker) ate " << name << " at (" << x << ", " << y << ")" << endl;
    worldRef.removeOrganism(this);
    worldRef.moveOrganism(attacker, x, y);

    // but also gets +3 power
    cout << "🎁 " << attacker->getName() << " ate Guarana and got +3 power" << endl;
    attacker->setPower(attacker->getPower() + 3);
}