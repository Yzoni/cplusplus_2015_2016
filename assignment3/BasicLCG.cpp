/**********************************************
/*   A Basic Linear Congruential Generator
/*  ---------------------------------------
/*  Program By: NickDMax for Dreamincode.net
/*  02/23/2007
/*
/*  You may use this code as you see fit
/**********************************************/
#include <iostream>
#include "BasicLCG.h"

using namespace std;

//This class will give satisfy basic
// random number considerations for
// games an general apps.
// WARNING: Not for Cryprographic use
//   Not for statistical methods.

BasicLCG::BasicLCG() {
    iCurrent = 0; //Chose a default seed
}

BasicLCG::BasicLCG(unsigned long iSeed) {
    iCurrent = iSeed;
}

void BasicLCG::seed(unsigned long iSeed) {
    iCurrent = iSeed;
}

//NOTE: a and c are selected for no particular properties
// and I have not run statistical tests on this number gernerator
// it is was written for demonstration purposes only.
unsigned long BasicLCG::nextNumber() {
    unsigned long iOutput;
    unsigned long iTemp;
    int i;
    //I only want to take the top two bits
    //This will shorten our period to (2^32)/16=268,435,456
    //Which seems like plenty to me.
    for (i = 0; i < 16; i++) {
        //Since this is mod 2^32 and our data type is 32 bits long
        // there is no need for the MOD operator.
        iCurrent = (3039177861 * iCurrent + 1);
        iTemp = iCurrent >> 30;
        iOutput = iOutput << 2;
        iOutput = iOutput + iTemp;
    }
    return iOutput;
}

unsigned short int BasicLCG::nextInt() {
    unsigned short int iOutput;
    unsigned long iTemp;
    int i;
    //No need to limit ourselves...
    for (i = 0; i < 8; i++) {
        //Since this is mod 2^32 and our data type is 32 bits long
        // there is no need for the MOD operator.
        iCurrent = (3039177861 * iCurrent + 1);
        iTemp = iCurrent >> 30;
        iOutput = iOutput << 2;
        iOutput = iOutput + (short int) iTemp;
    }
    return iOutput;
}

unsigned char BasicLCG::nextChar() {
    unsigned char cOutput;
    unsigned long iTemp;
    int i;
    for (i = 0; i < 4; i++) {
        iCurrent = (3039177861 * iCurrent + 1);
        iTemp = iCurrent >> 30;
        cOutput = cOutput << 2;
        cOutput = cOutput + (char) iTemp;
    }
    return cOutput;
}

int BasicLCG::nextBit() {
    iCurrent = (3039177861 * iCurrent + 1);
    return iCurrent >> 31;
}

double BasicLCG::nextDouble() {
    return (double) nextNumber() / 0xFFFFFFFF;
}

int BasicLCG::inRange(int iMin, int iMax) {
    int Diff;
    //IF the user put them in backwards then swap them
    if (iMax < iMin) {
        //Integer swap
        iMax = iMax ^ iMin; //iMax holds iMax ^ iMin
        iMin = iMax ^ iMin; //iMin= (iMax ^ iMin) ^ iMin = iMax (original)
        iMax = iMax ^ iMin; //iMax= (iMax ^ iMin) ^ iMax = iMin (original)
    }
    Diff = iMax - iMin + 1;
    return (int) (nextDouble() * Diff) + iMin;
}
