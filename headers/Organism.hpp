#pragma once
#include <iostream>

using namespace std;

class World;

class Organism {
   protected:
    int x, y;
    int power;
    int initiative;
    int age;
    bool isAlive = true;
    string name;
    World& worldRef;

   public:
    Organism(int x, int y, int power, int initiative, string name, World& worldRef);
    virtual ~Organism() = default;

    virtual void action() = 0;
    virtual void collision(Organism* attacker) = 0;
    virtual void draw() = 0;

    virtual void reproduce();
    virtual void fight(Organism* attacker);

    int getPower() const;
    int getInitiative() const;
    string getName() const;
    int getAge() const;
    int getX() const;
    int getY() const;
    bool getIsAlive() const;

    void setX(int x);
    void setY(int y);
    void setAge(int age);
    void setPosition(int x, int y);
    void setPower(int power);
    void setIsAlive(bool isAlive);
};
