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

    //test count, contains
    cout << endl << "count: " << bst1.count() << endl;

    cout << "  contains h2? " <<
            (bst1.contains("h", 2) ? "Y" : "N") << endl;
	 cout << "  contains c8? " <<
	    (bst1.contains("c", 8) ? "Y" : "N") << endl;
        cout << "  contains d7? " <<
            (bst1.contains("d", 7) ? "Y" : "N") << endl;
        cout << "  contains d3? " <<
            (bst1.contains("d", 3) ? "Y" : "N") << endl;
        cout << "  contains s11? " <<
            (bst1.contains("s", 11) ? "Y" : "N") << endl;
        cout << "  contains c4? " <<
            (bst1.contains("c", 4) ? "Y" : "N") << endl;
	cout << "  pre-order: ";
        bst1.printPreOrder();
        cout << endl << endl;

    cout << "  removing c4" << endl;
	bst1.remove("c", 4);
    cout << "  removing h2" << endl;
	bst1.remove("h", 2);
    cout << "  removing d7" << endl;
	bst1.remove("d", 7);
    cout << endl;
    
    cout << "  contains h2? " <<
            (bst1.contains("h", 2) ? "Y" : "N") << endl;
	 cout << "  contains c8? " <<
	    (bst1.contains("c", 8) ? "Y" : "N") << endl;
        cout << "  contains d7? " <<
            (bst1.contains("d", 7) ? "Y" : "N") << endl;
        cout << "  contains d3? " <<
            (bst1.contains("d", 3) ? "Y" : "N") << endl;
        cout << "  contains s11? " <<
            (bst1.contains("s", 11) ? "Y" : "N") << endl;
        cout << "  contains c4? " <<
            (bst1.contains("c", 4) ? "Y" : "N") << endl;
	cout << "  pre-order: ";
        bst1.printPreOrder();
        cout << endl << endl;

    return 0;
}
