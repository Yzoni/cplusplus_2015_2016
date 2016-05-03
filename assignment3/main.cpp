//
// Yorick de Boer (10786015)
//

#include <fstream>
#include <iostream>
#include "World.h"
#include "Menu.h"

using namespace std;

void init(World &world, Menu &menu) {
    menu.onOpenWorldFile(world);
}

int main(int argc, char *argv[]) {
    World world;
    Menu menu;

    init(world, menu);

    while (true) {
        world.getCurrentDisplayWorld(cout);
        menu.onShowMainMenu(cout);
        menu.getMainMenuInput(world, cout);
    }
}

