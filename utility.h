#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

class VirtualCard {
    public:
        VirtualCard();                          // constructor
        VirtualCard(char mySuit, int myVal);  // overloaded constructor
        ~VirtualCard();                         // destructor

        char getSuit();
        int getValue();
        

    private:
        char suit;
        int value;
};

#endif