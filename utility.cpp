#include "utility.h"

#include <iostream>
using namespace std;

VirtualCard::VirtualCard(string mySuit = "h", int myVal = 1) : suit(mySuit), value(myVal) { }

string VirtualCard::getSuit() {
    return suit;
}

int VirtualCard::getValue() {
    return value;
}

int convertSuit (string myS) {
    int myIntSuit = 0;
    if (myS == "c") {
        myIntSuit = 1;
    } else if (myS == "d") {
        myIntSuit = 2;
    } else if (myS == "s") {
        myIntSuit = 3;
    } else if (myS == "h") {
        myIntSuit = 4;
    }
    return myIntSuit;
}

bool operator==(VirtualCard& first, VirtualCard& second) {
    //compare suit
    int firstSuitRank = convertSuit(first.getSuit());
    int secondSuitRank = convertSuit(second.getSuit());

    if (firstSuitRank == secondSuitRank) {
        return true;
    } else if (first.getValue() == second.getValue()) {
        return true;
    } else {
        return false;
    }
}

bool operator<(VirtualCard& first, VirtualCard& second) {
    int firstSuitRank = convertSuit(first.getSuit());
    int secondSuitRank = convertSuit(second.getSuit());

    if (firstSuitRank < secondSuitRank) {
        return true;
    } else if (first.getValue() < second.getValue()) {
        return true;
    } else {
        return false;
    }
}

bool operator>(VirtualCard& first, VirtualCard& second) {
    int firstSuitRank = convertSuit(first.getSuit());
    int secondSuitRank = convertSuit(second.getSuit());

    if (firstSuitRank > secondSuitRank) {
        return true;
    } else if (first.getValue() > second.getValue()) {
        return true;
    } else {
        return false;
    }
}

