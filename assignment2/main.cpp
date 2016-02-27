/*
 * C++ Assignment 2
 * Date problems
 *
 * @author Yorick de Boer
 */

#include <fstream>

using namespace std;

int main() {

    ifstream inStream;
    ofstream outStream;

    inStream.open("/home/yorick/ClionProjects/cmethoden/assignment2/original.txt");
    if (inStream.fail()) {
        exit(1);
    }
    outStream.open("/home/yorick/ClionProjects/cmethoden/assignment2/compressed.txt");
    if (outStream.fail()) {
        exit(1);
    }

    char previous;
    char next;
    int count = 0;
    inStream.get(next);
    previous = next;
    while(! inStream.eof()) {
        if (next == previous) {
            count += 1;
        } else {
            if (count != 1) {
                if ((int) previous == 92 || ((int) previous >= 48 && (int) previous <= 57)) {
                    outStream << "\\"  << previous << count;
                } else {
                    outStream << previous << count;
                }
            } else {
                if ((int) previous == 92 || ((int) previous >= 48 && (int) previous <= 57)) {
                    outStream << "\\" << previous;
                } else {
                    outStream << previous;
                }
            }
            previous = next;
            count = 1;
        }
        inStream.get(next);
    }

    inStream.close();
    outStream.close();

    return 0;
}