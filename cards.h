//cards.h
//Authors: Your name and your partner's name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include "utility.h"

using namespace std;

class CardBST {

    public:
        CardBST();                  // constructor
        ~CardBST();                 // destructor
        bool insert(int value);     // insert value; return false if duplicate
        
    private:
        struct Node {
            VirtualCard nCard;
            Node *left, *right, *parent;
        };
        Node(int v=0) : nCard(), left(0), right(0), parent(0) { }

        Node *root;
    };


#endif
