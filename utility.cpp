#include "utility.h"

#include <iostream>
using namespace std;

VirtualCard::VirtualCard(string mySuit = "h", int myVal = 1) : suit(mySuit), value(myVal) { }

string VirtualCard::getSuit() {
    return suit;
}

int VirtualCard::getValue() {
    return val;
}

bool operator==(VirtualCard& first; VirtualCard& second) {
    //compare suit
    int firstSuitRank = 0;
    int secondSuitRank = 0;
    if (first.getSuit() == "c") {
        firstSuitRank = 1;
    } else if (first.getSuit() == "d") {
        firstSuitRank = 2;
    } else if (first.getSuit() == "s") {
        firstSuitRank = 3;
    } else if (first.getSuit() == "h") {
        firstSuitRank = 4;
    }

    if (second.getSuit() == "c") {
        secondSuitRank = 1;
    } else if (second.getSuit() == "d") {
        secondSuitRank = 2;
    } else if (second.getSuit() == "s") {
        secondSuitRank = 3;
    } else if (second.getSuit() == "h") {
        secondSuitRank = 4;
    }

    if (firstSuitRank == secondSuitRank) {
        return true;
    } else {
        return false;
    }
}