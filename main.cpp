#include <iostream>

#include "headers/World.hpp"

using namespace std;

class Human;

int main() {
    World world;
    Human* human = world.getHuman();
    world.drawWorld();

    while (true) {
        char option;

        cout << "Choose option: " << endl;
        cout << "q - quit" << endl;
        cout << "n - next turn" << endl;
        cout << "wasd - control human" << endl;

        if (human->getSpecialAbilityCooldown() == 0)
            cout << "x - activate human's special ability" << endl;
        else {
            cout << "\033[1;33mhuman's special ability is on cooldown! " << human->getSpecialAbilityCooldown() << " turns left...\033[0m" << endl;
            human->updatePower();
        }

        cin >> option;
        switch (option) {
            case 'q':
                return 0;
                break;
            case 'n':
                world.nextTurn();
                world.drawWorld();
                break;
            case 'w':
                cout << "\n🥷 Human will move up in the next turn \n\n";
                human->setDirection(1);
                break;
            case 'a':
                cout << "\n🥷 Human will move left in the next turn \n\n";
                human->setDirection(4);
                break;
            case 's':
                cout << "\n🥷 Human will move down in the next turn \n\n";
                human->setDirection(3);
                break;
            case 'd':
                cout << "\n🥷 Human will move right in the next turn \n\n";
                human->setDirection(2);
                break;
            case 'x':
                if (human->getSpecialAbilityCooldown() == 0)
                    human->activateSpecialAbilityCooldown();
                else
                    cout << "\n\033[1;31mHuman's special ability is on cooldown!\033[0m\n\n";
                break;

            default:
                cout << "\033[1;31mThere is no such option!\033[0m" << endl;
                break;
        }
    }

    return 0;
}