#include "utility.h"

#include <iostream>
using namespace std;

VirtualCard::VirtualCard(string mySuit = 'h', int myVal = 1) : suit(mySuit), value(myVal) { }

string VirtualCard::getSuit() {
    return suit;
}

int VirtualCard::getValue() {
    return val;
}