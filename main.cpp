#include <iostream>

#include "World.hpp"

using namespace std;

int main() {
    World world;
    world.drawWorld();

    while (true) {
        char option;

        cout << "Choose option: " << endl;
        cout << "q - quit" << endl;
        cout << "n - next turn" << endl;
        cout << "s - save game" << endl;
        cout << "l - load game" << endl;

        cin >> option;
        switch (option) {
            case 'q':
                return 0;
                break;
            case 'n':
                world.nextTurn();
                world.drawWorld();
                break;
            default:
                cout << "\033[1;31mThere is no such option!\033[0m" << endl;
                break;
        }
    }

    return 0;
}