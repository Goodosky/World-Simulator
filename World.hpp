#pragma once
#include <iostream>
#include <map>
#include <vector>

#include "Organism.hpp"

using namespace std;

class World {
   private:
    vector<vector<Organism*> > world;
    vector<Organism*> organisms;
    int worldWidth, worldHeight;
    int numberOfTurns;

   public:
    World();

    void nextTurn();
    void drawWorld();

    Organism* getOrganism(int x, int y);
    void moveOrganism(Organism* organism, int x, int y);
    void addOrganism(string organism_name, int x, int y);
    void removeOrganism(Organism* organism);

    void getRandomNeighborPosition(int& x, int& y, bool can_be_occupied = true);

    int getWidth() const { return worldWidth; };
    int getHeight() const { return worldHeight; };
};