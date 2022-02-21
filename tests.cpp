// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "cards.h"

#include <iostream>
#include <fstream>
using namespace std;


// creates two trees, 1 with stuff, and 1 empty
// read the files into 2 binary search trees
int main() {

    CardBST bst1, bst2;
    ifstream myfile;
    myfile.open("a0.txt");
    
    if (myfile.is_open()) {
        cout << " file is open " << endl;
    }

    myfile.close();

    // testing one insertion into BST
    bst1.insert("h", 1);
    bst1.insert("h", 2);
    bst1.insert("c", 8);
    bst1.insert("d", 7);
    bst1.insert("d", 3);


    return 0;
}
