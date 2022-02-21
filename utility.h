#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

class VirtualCard {
    public:
        VirtualCard();                          // constructor
        VirtualCard(string mySuit, int myVal);  // overloaded constructor
        ~VirtualCard();                         // destructor

        string getSuit();
        int getValue();

        int convertSuit (string myS); // helper function for overloaded operators
        
    private:
        string suit;
        int value;
        
};

#endif