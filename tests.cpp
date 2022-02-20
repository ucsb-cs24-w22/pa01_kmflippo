// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "cards.h"

#include <iostream>
#include <fstream>
using namespace std;


// creates two trees, for Alice and Bob
// read the files into 2 binary search trees
int main() {

    CardBST aliceBst, bobBst;
    ifstream myfile;
    myfile.open("a0.txt");
    
    if (myfile.is_open()) {
        cout << " file is open " << endl;
    }

    myfile.close();

    return 0;
}
