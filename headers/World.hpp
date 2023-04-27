#pragma once
#include <iostream>
#include <map>
#include <vector>

#include "Organism.hpp"
#include "OrganismsFactory.hpp"
#include "animals/Antelope.hpp"
#include "animals/Fox.hpp"
#include "animals/Sheep.hpp"
#include "animals/Turtle.hpp"
#include "animals/Wolf.hpp"
#include "plants/Dandelion.hpp"
#include "plants/Grass.hpp"
#include "plants/Guarana.hpp"

#define INITIAL_WORLD_FILLING 0.1    // 0-1
#define PLANT_REPRODUCTION_CHANCE 2  // 0-100

using namespace std;

class World {
   private:
    vector<vector<Organism*> > world;
    vector<Organism*> organisms;
    int worldWidth, worldHeight;
    int numberOfTurns;

    OrganismsFactory organismsFactory;

   public:
    World();

    void nextTurn();
    void drawWorld();

    Organism* getOrganism(int x, int y);
    void moveOrganism(Organism* organism, int x, int y);
    void addOrganism(string organism_name, int x, int y);
    void removeOrganism(Organism* organism);

    void getRandomNeighborPosition(int& x, int& y, int range = 1, bool can_be_occupied = true);

    int getWidth() const { return worldWidth; };
    int getHeight() const { return worldHeight; };
};