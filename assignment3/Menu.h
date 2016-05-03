//
// Yorick de Boer (10786015)
//

#ifndef CMETHODEN_MENU_H
#define CMETHODEN_MENU_H


#include <ostream>
#include "World.h"

class Menu {
public:
    void onExit();

    void onKillAllCells(World &world);

    void onRandomizeWorld(World &world);

    void onNextWorld(World &world);

    void onNextNWorlds(World &world, int n);

    void onOpenWorldFile(World &world);


    // Move menu
    void onShowMoveSubmmenu(std::ostream &outStream);

    int getMoveMenuInput(World &world, std::ostream &outStream);

    // Parameter menu
    void onShowParameterSubmenu(std::ostream &outStream);

    int getParameterMenuInput(World &world, std::ostream &ofStream);

    // Main menu
    void onShowMainMenu(std::ostream &ofStream);

    int getMainMenuInput(World &world, std::ostream &ofStream);
};


#endif //CMETHODEN_MENU_H
