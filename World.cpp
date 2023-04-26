#include "headers/World.hpp"

World::World() {
    numberOfTurns = 0;

    organismsFactory.registerOrganism<Wolf>("Wolf");
    organismsFactory.registerOrganism<Sheep>("Sheep");
    organismsFactory.registerOrganism<Sheep>("Fox");

    cout << "Give world width: ";
    cin >> worldWidth;

    cout << "Give world height: ";
    cin >> worldHeight;

    // Create two dimensional vector of pointers and fill it with nullptr
    world.resize(worldWidth, vector<Organism*>(worldHeight, nullptr));

    // Add random Organisms to organisms vector
    srand(time(nullptr));
    int number_of_organisms = worldHeight * worldWidth * INITIAL_WORLD_FILLING;

    for (int i = 0; i < number_of_organisms; i++) {
        // Draw organism name
        int random_index = rand() % organismsFactory.availableOrganisms.size();
        string organizm_name = organismsFactory.availableOrganisms[random_index];

        //  Draw position
        int x = rand() % worldWidth;
        int y = rand() % worldHeight;

        while (world[x][y] != nullptr) {
            x = rand() % worldWidth;
            y = rand() % worldHeight;
        }

        addOrganism(organizm_name, x, y);
    }

    // organisms.push_back(organismsFactory.create("Wolf", 0, 0, *this));
    // organisms.push_back(organismsFactory.create("Sheep", 0, 0, *this));
}

void World::nextTurn() {
    numberOfTurns++;

    cout << "\n\033[1;33m--- Turn: " << numberOfTurns << "---\033[0m\n";

    // Sort organisms by initiative and age
    sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if (a->getInitiative() == b->getInitiative()) {
            return a->getAge() > b->getAge();
        } else {
            return a->getInitiative() > b->getInitiative();
        }
    });

    cout << "Organisms: \n";
    for (Organism* organism : organisms) {
        cout << organism->getName() << " (" << organism->getX() << ", " << organism->getY() << ")\n";
    }

    cout << endl;

    // Do action
    for (int i = 0; i < organisms.size(); i++) {
        organisms[i]->setAge(organisms[i]->getAge() + 1);
        organisms[i]->action();
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
    organisms.push_back(organismsFactory.create(organism_name, x, y, *this));
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
    int direction = rand() % 4;

    for (int i = 0; i < 4; i++) {
        int new_x = x;
        int new_y = y;

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

        // ...if not, try a next direction
        direction = (direction + 1) % 4;
    }

    // If (can_be_occupied == false) and there is no free space, the coordinates will not change
}
