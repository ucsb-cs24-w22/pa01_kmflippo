#include "utility.h"

#include <iostream>
using namespace std;

VirtualCard::VirtualCard() : suit("h"), value(1) { }

VirtualCard::VirtualCard(string mySuit, int myVal) { 
    suit = mySuit;
    value = myVal;
}

char VirtualCard::getSuit() {
    return suit;
}

int VirtualCard::getValue() {
    return val;
}