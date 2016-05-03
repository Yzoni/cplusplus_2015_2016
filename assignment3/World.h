//
// Yorick de Boer (10786015)
//

#ifndef CMETHODEN_WORLD_H
#define CMETHODEN_WORLD_H


class World {
public:
    World();

    // Kill all the cells in the main world
    void killAllCells();

    // Copies the temporary world to the main world
    void update();

    // Gets the full world and puts it in standard output
    void getCurrentFullWorld(std::ostream &ofStream);

    // Gets the only the world in the current display
    void getCurrentDisplayWorld(std::ostream &ofStream);

    // Loads a world from a file from standard input
    void loadFromFile(std::istream &inStream);

    // Generates a random world using the the BasicLCG algorithm
    void genereateRandomWorld(unsigned probability);

    // Set the character to use to represent a death cell
    void setDeathCharacter(char character);

    // Set the character to use to represent an alive cell
    void setAliveCharacter(char character);

    // Move view right
    void moveViewRight(int stepSize);

    // Move view left
    void moveViewLeft(int stepSize);

    // Move view up
    void moveViewUp(int stepSize);

    // Move view down
    void moveViewDown(int stepSize);

    // Change the horizontal stepsize where the view moves by
    void setViewMoveStepSizeY(int stepSize);

    // Change the vertical stepsize where the view moves by
    void setViewMoveStepSizeX(int stepSize);

    // Set the probability of a cell spawning as alive in the random function
    void setRandomProbability(int prob);

    // Getter for the probability that a cell spawns as alive
    int getRandomrobability();

    int getXViewCoor();

    int getYViewCoor();

    int getXStepSize();

    int getYStepSize();

private:
    char current_world_array_[200][200];
    char next_world_array_[200][200];
    int size_x_;
    int size_y_;
    char death_char_;
    char alive_char_;
    int random_prob_;

    // VIEW
    int coor_x_view_;
    int coor_y_view_;
    int size_x_view_;
    int size_y_view_;
    int stepsize_x_view_;
    int stepsize_y_view_;


    char applyRule(int x, int y);

    void copyWorld();

    bool coorIsInView(int xView, int yView);

};


#endif //CMETHODEN_WORLD_H
