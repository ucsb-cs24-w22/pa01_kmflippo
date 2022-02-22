//cards.h
//Authors: Your name and your partner's name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include "utility.h"

using namespace std;

class CardBST {

    public:
        CardBST();                  // constructor
        ~CardBST();                 // destructor
        bool insert(string mySuit, int myVal);     // insert value; return false if duplicate
        void printPreOrder() const; //prints tree data pre-order to cout

        friend bool operator==(const VirtualCard& first, const VirtualCard& second);
        friend bool operator<(const VirtualCard& first, const VirtualCard& second);
        friend bool operator>(const VirtualCard& first, const VirtualCard& second);

        int convertSuit(string myS);
        string compare(VirtualCard first, VirtualCard second);

        void printInOrder() const; //print tree data in-order to cout
        void printPostOrder() const;     // print tree data post-order to cout
        int count() const;               // count of values
        bool contains(VirtualCard value) const;  // true if value is in tree

        VirtualCard getPredecessor(VirtualCard vCard) const;       // returns the predecessor value of the given value or 0 if there is none
        VirtualCard getSuccessor(VirtualCard vCard) const;         // returns the successor value of the given value or 0 if there is none
        bool remove(VirtualCard vCard);                    // deletes the Node containing the given value from the tree
        
    private:
        struct Node {
            VirtualCard nCard;
            Node *left, *right, *parent;
            Node(string s, int v) : nCard(s, v), left(0), right(0), parent(0) { }
        };
        

        Node *root;

        Node* getNodeFor(VirtualCard vCard, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
        void clear(Node *n); // for destructor
        bool insert(VirtualCard vCard, Node *n); // note overloading names for simplicity
        void printPreOrder(Node *n) const;
        void printInOrder(Node *n) const;
        void printPostOrder(Node *n) const;
        int count(Node *n) const;

        // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
        Node* getSuccessorNode(VirtualCard vCard) const;   // returns the Node containing the successor of the given value
        Node* getPredecessorNode(VirtualCard vCard) const; // returns the Node containing the predecessor of the given value
    };


#endif
