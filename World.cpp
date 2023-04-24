#include "World.hpp"

#include "animals/Wolf.hpp"

World::World() {
    numberOfTurns = 0;

    srand(time(nullptr));

    cout << "Give world width: ";
    cin >> worldWidth;

    cout << "Give world height: ";
    cin >> worldHeight;

    // Create two dimensional vector of pointers and fill it with nullptr
    world.resize(worldWidth, vector<Organism*>(worldHeight, nullptr));

    // Add random animals to organisms vector
    organisms.push_back(new Wolf(0, 0, *this));
    organisms.push_back(new Wolf(0, 0, *this));

    // Asign added animals to the world at random position
    for (auto& organism : organisms) {
        int x = rand() % worldWidth;
        int y = rand() % worldHeight;

        while (world[x][y] != nullptr) {
            x = rand() % worldWidth;
            y = rand() % worldHeight;
        }

        organism->setPosition(x, y);
        world[x][y] = organism;
    }
}

void World::nextTurn() {
    numberOfTurns++;

    cout << "\n\033[1;33m--- Turn: " << numberOfTurns << "---\033[0m\n";

    // Sort organisms by initiative
    sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if (a->getInitiative() == b->getInitiative()) {
            return a->getAge() > b->getAge();
        } else {
            return a->getInitiative() > b->getInitiative();
        }
    });

    cout << "Organisms: \n";
    // Do action
    for (Organism* organism : organisms) {
        cout << organism->getName() << " (" << organism->getX() << ", " << organism->getY() << ")\n";
    }

    cout << endl;

    // Do action
    for (Organism* organism : organisms) {
        organism->setAge(organism->getAge() + 1);
        cout << "Do action: " << organism->getName() << " (" << organism->getX() << ", " << organism->getY() << ")\n";
        organism->action();
    }
}

void World::drawWorld() {
    cout << endl;

    for (size_t y = 0; y < worldHeight; y++) {
        for (size_t x = 0; x < worldWidth; x++) {
            if (world[x][y] == nullptr) {
                cout << "⚪";
            } else {
                world[x][y]->draw();
            }
        }

        cout << endl;
    }

    cout << endl;
};

Organism* World::getOrganism(int x, int y) {
    return world[x][y];
}

void World::addOrganism(string organism_name, int x, int y) {
    if (organism_name == "Wolf") {
        organisms.push_back(new Wolf(x, y, *this));
    }

    world[x][y] = organisms.back();
}

void World::moveOrganism(Organism* organism, int x, int y) {
    world[organism->getX()][organism->getY()] = nullptr;
    world[x][y] = organism;
    organism->setPosition(x, y);
}

void World::removeOrganism(Organism* organism) {
    world[organism->getX()][organism->getY()] = nullptr;
    organisms.erase(remove(organisms.begin(), organisms.end(), organism), organisms.end());
}

void World::getRandomNeighborPosition(int& x, int& y, bool can_be_occupied) {
    while (true) {
        int new_x = x;
        int new_y = y;
        int direction = rand() % 4;

        switch (direction) {
            case 0:
                new_x--;
                break;
            case 1:
                new_x++;
                break;
            case 2:
                new_y--;
                break;
            case 3:
                new_y++;
                break;
        }

        //  return a new position if it's is in the world
        if (new_x >= 0 && new_x < worldWidth && new_y >= 0 && new_y < worldHeight) {
            if (can_be_occupied || world[new_x][new_y] == nullptr) {
                x = new_x;
                y = new_y;
                return;
            }
        }

        // ...if not, draw direction again
    }
}
