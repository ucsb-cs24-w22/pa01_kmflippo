#include "utility.h"

#include <iostream>
using namespace std;

VirtualCard::VirtualCard(string mySuit = "h", int myVal = 1) : suit(mySuit), value(myVal) { }

VirtualCard::~VirtualCard(){ }

string VirtualCard::getSuit() const{
    return suit;
}

int VirtualCard::getValue() const{
    return value;
}

int VirtualCard::getSuitRank() const {
    int myIntSuit = 0;
    if (suit == "c") {
        myIntSuit = 1;
    } else if (suit == "d") {
        myIntSuit = 2;
    } else if (suit == "s") {
        myIntSuit = 3;
    } else if (suit == "h") {
        myIntSuit = 4;
    }
    return myIntSuit;
}
