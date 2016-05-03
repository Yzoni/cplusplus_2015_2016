#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream> 

using namespace std;

// constant size of array makes things easier
const int lifeHeight = 200;
const int lifeWidth = 200;

class MyRandom // random number generator
{
public:

    // seed random generator
    void seed(int s) {
        //srand(s); //stub
        m_w = s;
        m_z = 0x371fbcde;
    }

    double random() // return random double between 0 and 1
    {
        //return rand()/((double)RAND_MAX); //stub
        //
        // ---------------------------------------
        // random generation by George Marsaglia
        // http://en.wikipedia.org/wiki/Random_number_generation#Computational_methods
        // ---------------------------------------
        m_z = 36969 * (m_z & 65535) + (m_z >> 16);
        m_w = 18000 * (m_w & 65535) + (m_w >> 16);
        unsigned int rint = (m_z << 16) + m_w;
        return rint / (double) ((unsigned int) (0xffffffff));  // 32-bit result
    }

private:
    int m_w;
    int m_z;

};

MyRandom myRandom; // global random generator object

class Menu; // forward declaration of Menu as World uses its parameters

class World // forward declaration of World as Menu uses methods of this class
{
public:

    // get cell status
    bool cell(int y, int x);

    // set cell status
    void cell(int y, int x, bool alive);

    // set all cells to dead
    void cleanLife();

    // randomize all cells
    void randomLife(Menu menu);

    // print all cells in the view
    void printLife(Menu menu);

    // move one timestep into the future
    void one();

private:

    // test if y,x is on the grid
    bool onGrid(int y, int x);

    // test if y,x is on the border of the grid
    bool onBorder(int y, int x);

    bool cells[lifeHeight][lifeWidth]; // array representing life/dead status of cells
    char neighbors[lifeHeight][lifeWidth]; // array representing neighbor count of cells
};

class Menu // class holding parameters and operationg on/with them
{
public:

    void init() // we didn't learn about constructors yet so initialization using init() function
    {
        stoppedFlag = false;
        randomProb = 0.4;
        viewPosX = -2;
        viewPosY = -2;
        viewSizeX = 80;
        viewSizeY = 40;
        viewStepX = viewSizeX / 5;
        viewStepY = viewSizeY / 5;
        go = 0;
        aliveCell = 'o';
        deadCell = ' ';
    }

    void printMenu() {
        cout << "[S]top [C]lean [R]andom [O]ne [G]o [M]ove [P]arameters [F]ile" << endl;
    }

    // read users input to menu
    void userInput(World &world) {
        if (go <= 0) {
            char c = cin.get();
            cin.clear();
            cin.ignore(10000, '\n');// clear remaining data in cin buffer
            switch (c) {
                case 's':
                case 'S':
                    cout << "Stopping" << endl;
                    stoppedFlag = true;
                    break;
                case 'c':
                case 'C':
                    cout << "Cleaning" << endl;
                    world.cleanLife();
                    break;
                case 'm':
                case 'M':
                    cout << "Moving" << endl;
                    move();
                    break;
                case 'r':
                case 'R':
                    cout << "Random" << endl;
                    world.randomLife(*this);
                    break;
                case 'o':
                case 'O':
                    world.one();
                    cout << "One" << endl;
                    break;
                case 'g':
                case 'G':
                    cout << "Go" << endl;
                    go = 100;
                    break;
                case 'p':
                case 'P':
                    cout << "Parameters" << endl;
                    parameters();
                    break;
                case 'f':
                case 'F':
                    cout << "File" << endl;
                    file(world);
                    break;
                default:;//cout<<"unkown menu option"<<endl;
            }
        }
        else {
            world.one();
            usleep(50000);
            go--;
        }
    }

    void printPosition() {
        cout << "view  X:" << viewPosX << " Y:" << viewPosY << " width:" << viewSizeX << " height:" << viewSizeY <<
        endl;
    }

    // move the view around
    void move() // move the view
    {
        cout << "        up  (w)" << endl;
        cout << "left(a) down(s) right(d)" << endl;
        char c = cin.get();
        cin.clear();
        cin.ignore(10000, '\n'); // clear remaining data in cin buffer
        switch (c) {
            case 'w':
                viewPosY -= viewStepY;
                cout << "up" << endl;
                break;
            case 'a':
                viewPosX -= viewStepX;
                cout << "left" << endl;
                break;
            case 's':
                viewPosY += viewStepY;
                cout << "down" << endl;
                break;
            case 'd':
                viewPosX += viewStepX;
                cout << "right" << endl;
                break;
            default:
                cout << "undefined move" << endl;
        }

        // not too small view coordinates
        if (viewPosY + viewSizeY / 2 < 0)
            viewPosY = -viewSizeY / 2;
        if (viewPosX + viewSizeX / 2 < 0)
            viewPosX = -viewSizeX / 2;

        // not too large view coordinates
        if (viewPosY > lifeHeight - viewSizeY / 2)
            viewPosY = lifeHeight - viewSizeY / 2;
        if (viewPosX > lifeWidth - viewSizeX / 2)
            viewPosX = lifeWidth - viewSizeX / 2;
    }

    // view and change parameters
    void parameters() {
        cout << " parameters:" << endl;
        cout << "1) viewStepX=" << viewStepX << ", view step size in X direction" << endl;
        cout << "2) viewStepY=" << viewStepY << ", view step size in X direction" << endl;
        cout << "3) randomProb=" << randomProb << ", prabability that a cell is alive after randomizing" << endl;
        cout << "4) aliveCell='" << aliveCell << "', prabability that a cell is alive after randomizing" << endl;
        cout << "5) deadCell='" << deadCell << "', prabability that a cell is alive after randomizing" << endl;
        cout << "type parameter number and new value" << endl;
        cout << "example: \" 3   0.7\" to set randomProb to 0.7." << endl;
        char buffer[1000];// large enough?
        cin.get(buffer, 1000);
        cin.clear();
        cin.ignore(10000, '\n');// clear remaining data in cin buffer
        cout << "typed: " << buffer << endl;
        stringstream ss;
        ss.str(buffer);
        int num;
        char c;
        ss >> num;
        switch (num) {
            case 1:
                int sizeX;
                ss >> sizeX;
                if (ss.fail())
                    cout << "error parsing integer" << endl;
                else
                    viewStepX = sizeX;
                break;
            case 2:
                int sizeY;
                ss >> sizeY;
                if (ss.fail())
                    cout << "error parsing integer" << endl;
                else
                    viewStepY = sizeY;
                break;
            case 3:
                double p;
                ss >> p;
                if (ss.fail())
                    cout << "error parsing double" << endl;
                else
                    randomProb = p;
                break;
            case 4:
                ss >> c;
                if (ss.fail())
                    cout << "error parsing character" << endl;
                else
                    aliveCell = c;
                break;
            case 5:
                ss >> c;
                if (ss.fail())
                    cout << "error parsing character" << endl;
                else
                    deadCell = c;
                break;
                cout << "undefined parameter number" << endl;
        }
    }

    // read file data to edit view
    void file(World &world) {
        cout << "enter filename:";
        char filename[1000];
        cin.get(filename, 1000);
        cin.clear();
        cin.ignore(10000, '\n');// clear remaining data in cin buffer
        ifstream myfile(filename);
        if (myfile.is_open()) // test if open
        {
            cout << "reading file '" << filename << "'" << endl;
            int fy = 0;
            string line;
            while (getline(myfile, line)) {
                cout << "line: " << line << endl;
                for (int fx = 0; fx < line.length(); fx++) {
                    bool alive = true;
                    if (line.at(fx) == '.' || line.at(fx) == ' ') // dead cell
                        alive = false;
                    cout << "fy:" << fy << " fx:" << fx << " alive:" << alive << endl;
                    world.cell(viewPosY + fy + 1, viewPosX + fx + 1, alive); // set status of cell
                }
                fy++;// next line
            }
            myfile.close();
        }
        else {
            cout << "could not read file '" << filename << "'" << endl;
        }
    }

    bool stoppedFlag;
    double randomProb;
    int viewPosX;
    int viewPosY;
    int viewSizeX;
    int viewSizeY;
    int viewStepX;
    int viewStepY;
    int go;
    char aliveCell;
    char deadCell;
};

// test if y,x is on the grid
bool World::onGrid(int y, int x) {
    return (y >= 0 && x >= 0 && y < lifeHeight && x < lifeWidth);
}

// test if y,x is on the border of the grid
bool World::onBorder(int y, int x) {
    return ((y == -1 || x == -1 || y == lifeHeight || x == lifeWidth) && // x or y coordinate on edge and
            (y >= -1 && y <= lifeHeight) && (x >= -1 && x <= lifeWidth)); // other coordinate on edge or on grid
}

// get cell status
bool World::cell(int y, int x) {
    if (onGrid(y, x))
        return cells[y][x];
    else
        return false;
}

// set cell status
void World::cell(int y, int x, bool alive) {
    if (onGrid(y, x))
        cells[y][x] = alive;
}

// set all cells to dead
void World::cleanLife() {
    for (int y = 0; y < lifeHeight; y++) {
        for (int x = 0; x < lifeWidth; x++) {
            cells[y][x] = false;
        }
    }
}

// randomize all cells
void World::randomLife(Menu menu) {
    for (int y = 0; y < lifeHeight; y++) {
        for (int x = 0; x < lifeWidth; x++) {
            double r = myRandom.random();
            if (r > menu.randomProb)
                cells[y][x] = false;
            else
                cells[y][x] = true;
        }
    }
}

// print all cells in the view
void World::printLife(Menu menu) {
    for (int y = 0; y < menu.viewSizeY; y++) {
        for (int x = 0; x < menu.viewSizeX; x++) {
            int cy = y + menu.viewPosY;
            int cx = x + menu.viewPosX;
            if (onGrid(cy, cx)) {
                if (cells[cy][cx])
                    cout << menu.aliveCell;
                else
                    cout << menu.deadCell;
            }
            else if (onBorder(cy, cx)) {
                cout << "#";
            }
            else
                cout << ".";
        }
        cout << endl;
    }
}

// move one timestep into the future
void World::one() {
    // count neighbors
    for (int y = 0; y < lifeHeight; y++) {
        for (int x = 0; x < lifeWidth; x++) {
            int neighborCount = 0;
            for (int ny = -1; ny <= 1; ny++) {
                for (int nx = -1; nx <= 1; nx++) {
                    if (!(ny == 0 && nx == 0)) // not center
                    {
                        int ty = y + ny;
                        int tx = x + nx;
                        if (cell(ty, tx)) {
                            neighborCount++;
                        }
                    }
                }
            }
            neighbors[y][x] = neighborCount;
            //cout<<neighborCount;
        }
        //cout<<endl;
    }
    // kill and spawn cells
    for (int y = 0; y < lifeHeight; y++) {
        for (int x = 0; x < lifeWidth; x++) {
            int neigborCount = neighbors[y][x];
            if (cells[y][x]) {
                if (neigborCount < 2 || neigborCount > 3)
                    cells[y][x] = false;
            }
            else {
                if (neigborCount == 3)
                    cells[y][x] = true;
            }
        }
    }
}

int main() {
    myRandom.seed(time(NULL));

    Menu menu;
    menu.init();
    World world;
    world.cleanLife(); // start with empty world

    do {
        menu.printPosition();
        world.printLife(menu); // print cells in view
        menu.printMenu();
        menu.userInput(world); // menu interaction
    } while (!menu.stoppedFlag);
}
