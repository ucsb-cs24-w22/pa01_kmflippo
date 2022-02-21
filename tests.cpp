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

    //testing opening the file
    ifstream myfile;
    myfile.open("a0.txt");
    
    if (myfile.is_open()) {
        cout << " file is open " << endl;
    }

    myfile.close();
    cout << " file is closed " << endl << endl;

    // testing insertion into BST
    bst1.insert("h", 2);
    bst1.insert("c", 8);
    bst1.insert("d", 7);
    bst1.insert("d", 3);
    bst1.insert("c", 4);
    bst1.insert("s", 5);
    bst1.insert("h", 4);
    bst1.insert("s", 8);
    bst1.insert("h", 6);
    bst1.insert("c", 9);
    bst1.insert("s", 10);

    // pre order, in order, and post order
    cout << "Pre Order: ";
    bst1.printPreOrder();
    cout << endl;
    cout << "In Order: ";
    bst1.printInOrder();
    cout << endl;
    cout << "Post Order: ";
    bst1.printPostOrder();
    cout << endl;

    //test count
    cout << endl << "count: " << bst1.count() << endl;

    //test operators
    
    return 0;
}
