#include "Organism.hpp"

#include "World.hpp"

Organism::Organism(int x, int y, int power, int initiative, string name, World& worldRef) : x(x), y(y), power(power), initiative(initiative), age(0), name(name), worldRef(worldRef) {}

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
