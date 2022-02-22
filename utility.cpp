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

string VirtualCard::getValStr() const {
    string myStr = "";
    if (value == 1) {
        myStr = "a";
    } else if (value == 11) {
        myStr = "j";
    } else if (value == 12) {
        myStr = "q";
    } else if (value == 13) {
        myStr = "k";
    } else {
        return to_string(value);
    }
    return myStr;
}
