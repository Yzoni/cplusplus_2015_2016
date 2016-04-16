/**********************************************
/*   A Basic Linear Congruential Generator
/*  ---------------------------------------
/*  Program By: NickDMax for Dreamincode.net
/*  02/23/2007
/*
/*  You may use this code as you see fit
/**********************************************/

#ifndef CMETHODEN_RANDOMWORLDGENERATOR_H
#define CMETHODEN_RANDOMWORLDGENERATOR_H


class BasicLCG {

private:
    unsigned long iCurrent;
public:
    BasicLCG();

    BasicLCG(unsigned long);

    void seed(unsigned long iSeed);

    unsigned long nextNumber(); //get the next random number
    unsigned short int nextInt();

    unsigned char nextChar();

    int nextBit();

    double nextDouble();

    int inRange(int min, int max);
};


#endif //CMETHODEN_RANDOMWORLDGENERATOR_H
