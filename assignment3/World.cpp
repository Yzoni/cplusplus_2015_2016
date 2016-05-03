//
// Yorick de Boer (10786015)
//

#include <fstream>
#include "World.h"
#include "BasicLCG.h"

using namespace std;

void World::setDeathCharacter(char character) {
    death_char_ = character;
}

void World::setAliveCharacter(char character) {
    alive_char_ = character;
}

void World::genereateRandomWorld(unsigned probability) {
    BasicLCG basicLCG(time(NULL));
    for (int y = 0; y < size_y_; y++) {
        for (int x = 0; x < size_x_; x++) {
            if ((basicLCG.nextInt() % 100) < probability) {
                current_world_array_[y][x] = alive_char_;
            } else {
                current_world_array_[y][x] = death_char_;
            }
        }
    }
}

void World::killAllCells() {
    for (int y = 0; y < size_y_; y++) {
        for (int x = 0; x < size_x_; x++) {
            current_world_array_[y][x] = death_char_;
        }
    }
}

void World::update() {
    for (int y = 0; y < size_y_; y++) {
        for (int x = 0; x < size_x_; x++) {
            next_world_array_[y][x] = applyRule(x, y);
        }
    }
    copyWorld();
}

void World::copyWorld() {
    for (int y = 0; y < size_y_; y++) {
        for (int x = 0; x < size_x_; x++) {
            current_world_array_[y][x] = next_world_array_[y][x];
        }
    }
}

char World::applyRule(int x, int y) {
    int countAlive = 0;
    int countDeath = 0;
    char currentCellStatus = current_world_array_[y][x];

    // Count death and alive neighbouring cells
    for (int xi = x - 1; xi <= (x + 1); xi++) {
        for (int yi = y - 1; yi <= (y + 1); yi++) {
            char neighbourCellStatus = current_world_array_[yi][xi];
            if ((yi != y) || (xi != x)) {
                if (neighbourCellStatus == alive_char_) {
                    countAlive++;
                } else {
                    countDeath++;
                }
            }
        }
    }

    // A live cell with less than 2 live neighbors dies
    if (currentCellStatus == alive_char_ && countAlive < 2) {
        return death_char_;
        // A live cell with 2 or 3 live neighbors lives on
    } else if (currentCellStatus == alive_char_ && (countAlive == 2 || countAlive == 3)) {
        return alive_char_;
        // A live cell with more than 3 live neighbors dies
    } else if (currentCellStatus == alive_char_ && (countAlive > 3)) {
        return death_char_;
        // A dead cell with 3 live neighbors becomes alive
    } else if (currentCellStatus == death_char_ && countAlive == 3) {
        return alive_char_;
    }
    return death_char_;
}

void World::getCurrentFullWorld(ostream &ofStream) {
    for (int y = 0; y < size_y_; y++) {
        for (int x = 0; x < size_x_; x++) {
            ofStream << current_world_array_[y][x];
        }
        ofStream << endl;
    }
}

void World::getCurrentDisplayWorld(ostream &ofStream) {
    int yi = coor_y_view_;
    int xi = coor_x_view_;

    int yt = yi;
    for (yt; yt < yi + size_y_view_; yt++) {
        int xt = xi;
        for (xt; xt < xi + size_x_view_; xt++) {
            ofStream << current_world_array_[yt][xt];
        }
        ofStream << endl;
    }
    ofStream << endl;
}

void World::loadFromFile(istream &inStream) {
    killAllCells();
    char currentChar;
    int countY = 0;
    int countX = 0;
    inStream.get(currentChar);
    while (!inStream.eof()) {
        if (currentChar == '\n') {
            countY++;
            countX = 0;
        }
        current_world_array_[countY][countX] = currentChar;
        inStream.get(currentChar);
        countX++;
    }
}

void World::moveViewRight(int stepSize) {
    int outer_new_x_coor = coor_x_view_ + size_x_view_;
    int new_x_coor = coor_x_view_ + stepSize;
    if (coorIsInView(outer_new_x_coor, coor_y_view_)) {
        coor_x_view_ = new_x_coor;
    }
}

void World::moveViewLeft(int stepSize) {
    int new_x_coor = coor_x_view_ - stepSize;
    if (coorIsInView(new_x_coor, coor_y_view_)) {
        coor_x_view_ = new_x_coor;
    }
}

void World::moveViewUp(int stepSize) {
    int new_y_coor = coor_x_view_ + stepSize;
    if (coorIsInView(coor_x_view_, new_y_coor)) {
        coor_y_view_ = new_y_coor;
    }
}

void World::moveViewDown(int stepSize) {
    int outer_new_y_coor = coor_y_view_ + size_y_view_;
    int new_y_coor = coor_y_view_ + stepSize;
    if (coorIsInView(coor_x_view_, outer_new_y_coor)) {
        coor_y_view_ = new_y_coor;
    }
}

bool World::coorIsInView(int xView, int yView) {
    if (xView > 0 || xView < size_x_) {
        if (yView > 0 || yView < size_y_) {
            return true;
        }
    }
    return false;
}

int World::getXViewCoor() {
    return coor_x_view_;
}

int World::getYViewCoor() {
    return coor_y_view_;
}

int World::getXStepSize() {
    return stepsize_x_view_;
}

int World::getYStepSize() {
    return stepsize_y_view_;
}

void World::setViewMoveStepSizeY(int stepSize) {
    if (stepSize > 0) {
        stepsize_y_view_ = stepSize;
    }
}

void World::setViewMoveStepSizeX(int stepSize) {
    if (stepSize > 0) {
        stepsize_x_view_ = stepSize;
    }
}

void World::setRandomProbability(int prob) {
    if (prob >= 0 && prob <= 100) {
        random_prob_ = prob;
    }
}

int World::getRandomrobability() {
    return random_prob_;
}

World::World() : size_y_(200),
                 size_x_(200),
                 death_char_('.'),
                 alive_char_('#'),
                 coor_x_view_(0),
                 coor_y_view_(0),
                 size_x_view_(80),
                 size_y_view_(40),
                 stepsize_x_view_(1),
                 stepsize_y_view_(1),
                 random_prob_(50) {
}




















