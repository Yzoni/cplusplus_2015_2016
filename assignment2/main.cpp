/*
 * C++ Assignment 2
 * Date problems
 *
 * @author Yorick de Boer
 */

#include <fstream>

using namespace std;

int decompress(string inputfile, string outputfile);

int compress(string inputfile, string outputfile);

int compress(string inputfile, string outputfile) {
    ifstream inStream;
    ofstream outStream;

    inStream.open(inputfile);
    if (inStream.fail()) {
        exit(1);
    }
    outStream.open(outputfile);
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
            // If two or more the same characters are found after each other
            if (count != 1) {
                // Character is a slash or an integer
                if (previous == '\\' || (previous >= '0' && previous <= '9')) {
                    outStream << "\\"  << previous << count;
                } else {
                    outStream << previous << count;
                }
            } else {
                // Character is a slash or an integer
                if (previous == '\\' || (previous >= '0' && previous <= '9')) {
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

int decompress(string inputfile, string outputfile) {
    ifstream inStream;
    ofstream outStream;
    inStream.open(inputfile);
    if (inStream.fail()) {
        exit(1);
    }
    outStream.open(outputfile);
    if (outStream.fail()) {
        exit(1);
    }

    int tempCount;
    int count = -1;
    bool escapeFlag = false;
    char lastChar;
    char currentChar;

    inStream.get(currentChar);
    lastChar = currentChar;
    while (!inStream.eof()) {
        if (currentChar >= '0' && currentChar <= '9' && !escapeFlag) {
            escapeFlag = false;
            tempCount = count;
            count = currentChar - '0'; // Convert back to integer
            if (tempCount > 0) {
                count = (tempCount * 10) + count;
            }
        } else if (currentChar == '\\' and !escapeFlag) {
            escapeFlag = true;
        } else {
            escapeFlag = false;
            if (count > 0) {
                count--;
            }
            for (int i = -1; i < count; i++) {
                outStream << lastChar;
            }
            count = 0;
            lastChar = currentChar;
        }
        inStream.get(currentChar);
    }
    outStream << currentChar;

    inStream.close();
    outStream.close();

    return 0;
}

int main() {
    compress("/home/yorick/ClionProjects/cmethoden/assignment2/original.txt",
             "/home/yorick/ClionProjects/cmethoden/assignment2/compressed.txt");
    decompress("/home/yorick/ClionProjects/cmethoden/assignment2/compressed.txt",
               "/home/yorick/ClionProjects/cmethoden/assignment2/decompressed.txt");
}