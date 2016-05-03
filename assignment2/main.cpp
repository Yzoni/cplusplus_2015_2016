/*
 * C++ Assignment 2
 * Date problems
 *
 * @author Yorick de Boer
 */

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int decompress(istream &inStream, ostream &outStream);

int compress(istream &inStream, ostream &outStream);

int compress(istream &inStream, ostream &outStream) {
    char previous;
    char next;
    int count = 0;
    inStream.get(next);
    previous = next;
    while (!inStream.eof()) {
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

    return 0;
}

int decompress(istream &inStream, ostream &outStream) {
    int tempCount;
    int count = -1;
    bool escapeFlag = false;
    char lastRealChar;
    char currentChar;

    inStream.get(currentChar);
    lastRealChar = currentChar;
    while (!inStream.eof()) {
        if (currentChar >= '0' && currentChar <= '9' && !escapeFlag) {
            escapeFlag = false;
            tempCount = count;
            count = currentChar - '0'; // Convert char to integer value
            if (tempCount > 0) {
                count = (tempCount * 10) + count;
            }
        } else if (currentChar == '\\' and !escapeFlag) {
            escapeFlag = true;
        } else {
            if (count > 0) {
                count--;
            }
            for (int i = -1; i < count; i++) {
                outStream << lastRealChar;
            }
            escapeFlag = false;
            count = 0;
            lastRealChar = currentChar;
        }
        inStream.get(currentChar);
    }
    outStream << currentChar;

    return 0;
}


int main(int argc, char *argv[]) {

    if (argc < 2) {
        cout << "Too few arguments. \n";
        cout << "MyCompress <flag> [<input-filename>] [<output-filename>] \n";
    } else if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            cout << "MyCompress <flag> [<input-filename>] [<output-filename>] \n";
        } else if (strcmp(argv[1], "-d") == 0) {
            decompress(cin, cout);
        } else if (strcmp(argv[1], "-c") == 0) {
            compress(cin, cout);
        }
    } else if (argc == 4) {
        ifstream inStream;
        ofstream outStream;

        inStream.open(argv[2]);
        if (inStream.fail()) {
            cout << "In stream failed";
        }
        outStream.open(argv[3]);
        if (outStream.fail()) {
            cout << "Out stream failed";
        }
        if (strcmp(argv[1], "-c") == 0) {
            compress(inStream, outStream);
        } else if (strcmp(argv[1], "-d") == 0) {
            decompress(inStream, outStream);
        } else {
            cout << "MyCompress <flag> [<input-filename>] [<output-filename>] \n";
        }
    } else {
        cout << "Invalid amount of arguments. \n";
        cout << "MyCompress <flag> [<input-filename>] [<output-filename>] \n";
    }
}