#ifndef CMETHODEN_WORLD_H
#define CMETHODEN_WORLD_H


class World {
public:
    World();

    void killAllCells();

    void update();

    void getCurrentFullWorld(std::ostream &ofStream);

    void getCurrentDisplayWorld(std::ostream &ofStream);

    void loadFromFile(std::istream &inStream);

    void genereateRandomWorld(unsigned probability);

    void setDeathCharacter(char character);

    void setAliveCharacter(char character);

    void moveViewRight(int stepSize);

    void moveViewLeft(int stepSize);

    void moveViewUp(int stepSize);

    void moveViewDown(int stepSize);

    void setViewMoveStepSizeY(int stepSize);

    void setViewMoveStepSizeX(int stepSize);

    void setRandomProbability(unsigned int prob);

    unsigned int getRandomrobability();

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
    unsigned random_prob_;

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
