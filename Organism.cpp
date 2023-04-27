#include "headers/Organism.hpp"

#include "headers/World.hpp"

Organism::Organism(int x, int y, int power, int initiative, string name, World& worldRef) : x(x), y(y), power(power), initiative(initiative), age(0), name(name), worldRef(worldRef) {}

void Organism::reproduce() {
    //  Draw position of new organism
    int new_x = x;
    int new_y = y;
    worldRef.getRandomNeighborPosition(new_x, new_y, 1, false);

    // Add new organism to the world.
    if (x != new_x || y != new_y) {
        worldRef.addOrganism(name, new_x, new_y);
        cout << "💞 " << name << " has reproduced. Added " << name << " at (" << new_x << ", " << new_y << ")" << endl;
    } else {
        cout << "💔 " << name << " tried to reproduce, but there was no space around" << endl;
    }
}

void Organism::fight(Organism* attacker) {
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

int Organism::getPower() const {
    return power;
}

int Organism::getInitiative() const {
    return initiative;
}

string Organism::getName() const {
    return name;
}

int Organism::getAge() const {
    return age;
}

int Organism::getX() const {
    return x;
}

int Organism::getY() const {
    return y;
}

bool Organism::getIsAlive() const {
    return isAlive;
}

void Organism::setX(int x) {
    this->x = x;
}

void Organism::setY(int y) {
    this->y = y;
}

void Organism::setAge(int age) {
    this->age = age;
}

void Organism::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Organism::setPower(int power) {
    this->power = power;
}

void Organism::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}