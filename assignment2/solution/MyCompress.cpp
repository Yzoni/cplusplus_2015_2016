#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// determine character length of string representation of number count
int digitLength(int count) {
    stringstream ss;
    ss << count;
    int length = ss.str().length();
    return length;
}

// write character 'lastc' followed by sequence length 'count' to outfile
// adds the number of character written to outputCount 
void writeSequence(ostream &outfile, char lastc, int count, int &outputCount) {
    outfile.put(lastc);
    outputCount++;
    if (count > 1)
        outfile << count;
    outputCount += digitLength(count);
}

// compress infile to outfile
void compress(istream &infile, ostream &outfile) {
    char c;
    char lastc;
    bool lastcValid = false;// at first loop lastc variable is not valid
    int count = 1;
    int inputCount = 0, outputCount = 0;// character counters
    while (infile.get(c)) {
        inputCount++;
        if (lastcValid && lastc == c) // character sequence
        {
            count++;
        }
        else // sequence stops
        {
            if (lastcValid)
                writeSequence(outfile, lastc, count, outputCount);
            if ((c >= '0' && c <= '9') || c == '\\') // number or slash
            {
                outfile.put('\\');
                outputCount++; // add protecting slash
            }
            count = 1;
            lastc = c;
            lastcValid = true;
        }
    }
    if (lastcValid) writeSequence(outfile, lastc, count, outputCount);
    cerr << endl << "---compression ratio (" << outputCount << "/" << inputCount << "): "
    << outputCount / (double) inputCount << endl;
}

// decompress infile to outfile
void decompress(istream &infile, ostream &outfile) {
    char c;
    char lastc;
    bool lastcValid = false;// at first loop lastc variable is not valid
    bool numberMode = false;// we are not in reading a number mode
    bool slashMode = false; // we are not in reading after a slash mode
    int count = 1;
    int inputCount = 0, outputCount = 0;// character counters
    while (true) {
        bool continueReading = infile.get(c);
        if (continueReading) {
            inputCount++;
        }
        if (!slashMode and (c >= '0' && c <= '9')) {
            if (!numberMode)
                count = c - '0';
            else {
                count *= 10;
                count += c - '0';
            }
            numberMode = true; // go to numberMode
        }
        else {
            if (!slashMode and c == '\\') {
                slashMode = true; // go to slashmode
            }
            else {
                if (lastcValid) {
                    for (int i = 0; i < count; i++) {
                        outfile.put(lastc);
                        outputCount++;
                    }
                    count = 1;
                }
                lastc = c;
                lastcValid = true;
                slashMode = false; // go out of slashmode
                numberMode = false; // go out of numberMode
            }
        }
        if (!continueReading)
            break; // done processing last character so stop
    }
    cerr << endl << "---decompression ratio (" << outputCount << "/" << inputCount << "): "
    << outputCount / (double) inputCount << endl;
}

int main(int argc, char **argv) {
    if (argc < 2 ||
        (argc >= 2 && ((string) argv[1]) == "-h")) {
        cerr << "Name" << endl;
        cerr << "	MyCompress" << endl;
        cerr << "" << endl;
        cerr << "Synopsis" << endl;
        cerr << "" << endl;
        cerr << "	MyCompress <flag> [<input-filename>] [<output-filename>]" << endl;
        cerr << "" << endl;
        cerr << "Description" << endl;
        cerr << "" << endl;
        cerr << "	Compresses and decompresses text files." << endl;
        cerr << "	If no output filename is given it writes to standard output (stdout)." << endl;
        cerr << "	If no input filename is given it reads from standard input (stdin)." << endl;
        cerr << "" << endl;
        cerr << "Options for <flag>" << endl;
        cerr << "" << endl;
        cerr << "  	-h 	give this usage information and exit" << endl;
        cerr << "  	-c	compress the input file and write result to output file" << endl;
        cerr << "  	-d	decompress the input file and write result to output file" << endl;
        cerr << "" << endl;
        cerr << "Example Usage" << endl;
        cerr << "" << endl;
        cerr << "	MyCompress -c input.txt output.txt  # compress input.txt to output.txt" << endl;
        cerr << "	cat output.txt | MyCompress -d  # read from stdin, decompress to stdout" << endl;
        cerr << "" << endl;
        exit(1);
    }

    ofstream outfile;
    if (argc > 3) {
        char *output_filename = argv[3];
        outfile.open(output_filename);
        if (!outfile.is_open()) {
            cerr << "Couldn't open output file '" << output_filename << "'" << endl;
            exit(1);
        }
    }

    ifstream infile;
    if (argc > 2) {
        char *input_filename = argv[2];
        infile.open(input_filename);
        if (!infile.is_open()) {
            cerr << "Couldn't open input file '" << input_filename << "'" << endl;
            exit(1);
        }
    }

    string code = argv[1];
    if (code == "-c")
        compress(infile.is_open() ? infile : cin,
                 outfile.is_open() ? outfile : cout);
    else if (code == "-d")
        decompress(infile.is_open() ? infile : cin,
                   outfile.is_open() ? outfile : cout);
    else {
        cerr << "Invalid input, use '-h' flag for help" << endl;
        exit(1);
    }

    infile.close();
    outfile.close();
}
