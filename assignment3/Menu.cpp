//
// Yorick de Boer (10786015)
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Menu.h"

using namespace std;


void Menu::onExit() {
    exit(0);
}

void Menu::onKillAllCells(World &world) {
    world.killAllCells();
}

void Menu::onRandomizeWorld(World &world) {
    world.genereateRandomWorld(world.getRandomrobability());
}

void Menu::onNextWorld(World &world) {
    system("clear");
    world.getCurrentDisplayWorld(cout);
    world.update();
}

void Menu::onNextNWorlds(World &world, int n) {
    for (int i = 0; i < n; i++) {
        system("clear");
        world.getCurrentDisplayWorld(cout);
        world.update();
        system("sleep .1");
    }
}

void Menu::onOpenWorldFile(World &world) {
    world.killAllCells();

    ifstream inStream;
    char input_file_name[1024];
    cout << "Give path to world: ";
    cin >> input_file_name;
    inStream.open(input_file_name);
    if (inStream.fail()) {
        cout << "In stream failed \n";
        cout << "Generating random world... \n";
        world.genereateRandomWorld(world.getRandomrobability());
    } else {
        world.loadFromFile(inStream);
    }
}

void Menu::onShowMoveSubmmenu(std::ostream &ofStream) {
    ofStream << "r: moveRigth, l: moveLeft, u: moveUp, d: moveDown \n";
}

void Menu::onShowParameterSubmenu(std::ostream &ofStream) {
    ofStream <<
    "h: horizontalStepSize, v: verticalStepSize, p: probOnRandomGrid, d: deathCharacter, a: aliveCharacter \n";
}

void Menu::onShowMainMenu(std::ostream &ofStream) {
    ofStream << "e: exit, c: killAll, r: randomize, f:nextWorld, g: next100Worlds, o:openFile, q:parameterMenu, "
            "m:moveMenu \n";
}

int Menu::getMainMenuInput(World &world, std::ostream &ofStream) {
    ofStream << "Main command: ";
    char command;
    cin >> command;

    switch (command) {
        case 'e':
            onExit();
            return 0;
        case 'c':
            onKillAllCells(world);
            return 0;
        case 'r':
            onRandomizeWorld(world);
            return 0;
        case 'f':
            onNextWorld(world);
            return 0;
        case 'g':
            onNextNWorlds(world, 100);
            return 0;
        case 'o':
            onOpenWorldFile(world);
            return 0;
        case 'q':
            onShowParameterSubmenu(ofStream);
            getParameterMenuInput(world, ofStream);
            return 0;
        case 'm':
            onShowMoveSubmmenu(ofStream);
            getMoveMenuInput(world, ofStream);
            return 0;
        default:
            ofStream << "Invalid command";
            return 1;
    }
}

int Menu::getMoveMenuInput(World &world, std::ostream &ofStream) {
    ofStream << "Move command: ";
    char command;
    cin >> command;

    switch (command) {
        case 'r':
            world.moveViewRight(world.getXStepSize());
            return 0;
        case 'l':
            world.moveViewLeft(world.getXStepSize());
            return 0;
        case 'u':
            world.moveViewUp(world.getYStepSize());
            return 0;
        case 'd':
            world.moveViewDown(world.getYStepSize());
            return 0;
        default:
            ofStream << "Invalid command";
            return 1;
    }
}

int Menu::getParameterMenuInput(World &world, std::ostream &ofStream) {
    ofStream << "Parameter command: ";
    char command;
    cin >> command;

    switch (command) {
        case 'h':
            int new_step_size_x;
            ofStream << "Step size X (current: " << world.getXStepSize() << "): ";
            cin >> new_step_size_x;
            world.setViewMoveStepSizeX(new_step_size_x);
            return 0;
        case 'v':
            int new_step_size_y;
            ofStream << "Step size Y (current: " << world.getYStepSize() << "): ";
            cin >> new_step_size_y;
            world.setViewMoveStepSizeY(new_step_size_y);
            return 0;
        case 'p':
            int new_prob_alive;
            ofStream << "Set probability of alive cell: ";
            cin >> new_prob_alive;
            if (cin.fail()) {
                cout << "Input is not a number \n";
            }
            world.setRandomProbability(new_prob_alive);
            return 0;
        case 'd':
            char new_death_character;
            ofStream << "Choose character: ";
            cin >> new_death_character;
            world.setDeathCharacter(new_death_character);
            world.update();
            return 0;
        case 'a':
            char new_alive_character;
            ofStream << "Choose character: ";
            cin >> new_alive_character;
            world.setAliveCharacter(new_alive_character);
            world.update();
            return 0;
        default:
            cout << "Invalid command";
            return 1;
    }
}


