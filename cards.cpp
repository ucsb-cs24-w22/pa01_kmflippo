//cards.cpp
//Authors: Kelly Flippo
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>

using std::cout;

CardBST::CardBST() : root(nullptr) { }

// destructor deletes all nodes

CardBST::~CardBST() {
    clear(root);
}

// recursive helper for destructor
void CardBST::clear(Node *n) {
        if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}


bool operator==(const VirtualCard& first, const VirtualCard& second) {
    //compare suit
    if (first.getSuit() == second.getSuit() && first.getValue() == second.getValue()) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const VirtualCard& first, const VirtualCard& second) {
    //compare suit
    if (first.getSuit() == second.getSuit() && first.getValue() == second.getValue()) {
        return false;
    } else {
        return true;
    }
}

bool operator<(const VirtualCard& first, const VirtualCard& second) {
    int firstSuitRank = first.getSuitRank();
    int secondSuitRank = second.getSuitRank();

    if (firstSuitRank < secondSuitRank) {
        return true;
    } else if (firstSuitRank > secondSuitRank) {
        return false;
    }
        else if (first.getValue() < second.getValue()) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const VirtualCard& first, const VirtualCard& second) {
    int firstSuitRank = first.getSuitRank();
    int secondSuitRank = second.getSuitRank();

    if (firstSuitRank > secondSuitRank) {
        return true;
    } else if (firstSuitRank < secondSuitRank) {
        return false;
    } 
    else if (first.getValue() > second.getValue()) {
        return true;
    } else {
        return false;
    }
}

string CardBST::compare(VirtualCard first, VirtualCard second) {
    if (first > second) {
        return "card 1 is greater than card 2";
    } else if (first < second) {
        return "card 1 is less than card 2";
    } else if (first == second) {
        return "card 1 is equal to card 2";
    } else {
        return "there is a problem with the overloaded operators";
    }
}

// insert value in tree; return false if duplicate
bool CardBST::insert(string mySuit, int myVal) {
    // handle special case of empty tree first
    if (!root) {
	    root = new Node(mySuit, myVal);
	    return true;
    }
    // otherwise use recursive helper
    VirtualCard vCard(mySuit, myVal);
    return insert(vCard, root);
}

// recursive helper for insert (assumes n is never 0)
bool CardBST::insert(VirtualCard vCard, Node *n) {
    if (vCard == n->nCard){
         return false;
    }
    if (vCard < n->nCard) {
        if (n->left){
            return insert(vCard, n->left);
        }
	    else {
	        n->left = new Node(vCard.getSuit(), vCard.getValue());
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	if (n->right){
        return insert(vCard, n->right);
    }
	else {
	    n->right = new Node(vCard.getSuit(), vCard.getValue());
	    n->right->parent = n;
	    return true;
	}
    }
}


// print tree data pre-order
void CardBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void CardBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->nCard.getSuit() << n->nCard.getValue() << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void CardBST::printInOrder() const {
    printInOrder(root);
}

void CardBST::printInOrder(Node *n) const {
    // IMPLEMENT HERE
    if (n) {
        printInOrder(n->left);
        cout << n->nCard.getSuit() << " " << n->nCard.getValStr() << endl;
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void CardBST::printPostOrder() const {
    printPostOrder(root);
}

void CardBST::printPostOrder(Node *n) const {
    // IMPLEMENT HERE
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->nCard.getSuit() << n->nCard.getValue() << " ";
    }
}

// return count of values
int CardBST::count() const {
    return count(root);
}

// recursive helper for count
int CardBST::count(Node *n) const {
    if (!root){
        return 0;
    }
    if (!(n->left) && !(n->right)){
        return 1;
    } else if (n->left && n->right){
        return 1 + count(n->left) + count(n->right);
    } else if (n->left){
        return 1 + count(n->left);
    } else {
        return 1 + count(n->right);
    }
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
CardBST::Node* CardBST::getNodeFor(VirtualCard vCard, Node* n) const{
    
    if (!n){
        return nullptr;
    }


    // basecase: at correct node
    if (n->nCard == vCard){
            return n;
    } 
    
    // case1 val < n
    if (vCard < n->nCard){
        return getNodeFor(vCard, n->left);
    } 

    // case2 val > n   (value > n->info)
    else{
        return getNodeFor(vCard, n->right);
    } 

}

// returns true if value is in the tree; false if not
bool CardBST::contains(string mySuit, int myVal) const {
    VirtualCard vCard(mySuit, myVal);
    Node* valNode = getNodeFor(vCard, root);
    if (valNode == nullptr) {
        return false;
    }
    return true;
}

// return minimum Card
VirtualCard CardBST::getMinCard() {
    Node* lefttest = root;
    if (root->left){
        lefttest = root->left;
        while (lefttest->left){
            lefttest = lefttest->left;
        } 
    }
    return lefttest->nCard;
}

// return max Card
VirtualCard CardBST::getMaxCard() {
    Node* rightest = root;
    if (root->right){
        rightest = root->right;
        while (rightest->right){
            rightest = rightest->right;
        } 
    }
    return rightest->nCard;
}

// returns the Node containing the predecessor of the given value
CardBST::Node* CardBST::getPredecessorNode(VirtualCard vCard) const{
    // basecase root is null
    
    if (!root) {
        return NULL;
    }
    
    if (root->left){
        Node* lefttest = root->left;
        while (lefttest->left){
            lefttest = lefttest->left;
        } 
        if (lefttest->nCard == vCard){
            return nullptr;
        }
    }

    // find key
    Node* valNode = getNodeFor(vCard, root);
    // case 1: has a left subtree, return rightmost child of left subtree
    if (valNode->left) {
        Node* p = valNode->left;
        while (p->right) {
            p = p->right;
        }
        return p;
    }

    // case 2: has left child - left tree leftmost
    if (valNode->left){
        Node* temp = valNode->left;
        while (temp->right){
            temp = temp->right;
        }
        return temp;
    }

    // case 3: no right child - up the ancestors until you find ancestor > value
    if (!valNode->left) {
        Node* temp = valNode->parent;
        while (temp->nCard > vCard && temp != root) {
            temp = temp->parent;
        }
        return temp;
    }

    return nullptr;
}

// returns the predecessor value of the given value or 0 if there is none

VirtualCard CardBST::getPredecessor(string mySuit, int myVal) const{
    VirtualCard vCard(mySuit, myVal);
    Node* n = getPredecessorNode(vCard);
    if (n == NULL) {
        VirtualCard newCard("0", 0);
        return newCard;
    }
    return n->nCard; 
}

// returns the Node containing the successor of the given value
CardBST::Node* CardBST::getSuccessorNode(VirtualCard vCard) const{
    // case 1: list empty
    if (!root){
        return NULL;
    }

    Node* valNode = getNodeFor(vCard, root);

    // case 1.5: furthest right, return 0
    Node* farRight = root;
    while (farRight->right) {
        farRight = farRight->right;
    }
    
    if (farRight == valNode) {
        return nullptr;
    }


    // case 2: has right child - right tree leftmost
    if (valNode->right){
        Node* temp = valNode->right;
        while (temp->left){
            temp = temp->left;
        }
        return temp;
    }

    // case 3: no right child - up the ancestors until you find ancestor > value
    if (!valNode->right) {
        Node* temp = valNode->parent;
        while (temp->nCard < vCard && temp != root) {
            temp = temp->parent;
        }
        return temp;
    }

    return nullptr;
}

// returns the successor value of the given value or 0 if there is none
VirtualCard CardBST::getSuccessor(string mySuit, int myVal) const{
    VirtualCard vCard(mySuit, myVal);
    Node* n = getSuccessorNode(vCard);
    if (n == NULL){
        VirtualCard newCard("0", 0);
        return newCard;
    }
    return n->nCard;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool CardBST::remove(string mySuit, int myVal){
    VirtualCard vCard(mySuit, myVal);
    if (!root){
        return false;
    }

    Node* valNode = getNodeFor(vCard, root);
    if (!valNode){
        return false;
    }

     // case 1: leaf node
        // go to parent (if possible), assign proper side with null, remove node

    if ((!valNode->left) && !(valNode->right)){
        if(valNode == root){
            root = nullptr;
            delete valNode;
            return true;
        }
        Node* vParent = valNode->parent;
        if (valNode == vParent->left){
            delete valNode;
            vParent->left = nullptr;
        }
        if (valNode == vParent->right){
            delete valNode;
            vParent->right = nullptr;
        }
       
        return true;
    }

    // case2: node with only one child
        // save parent and child, assign proper parent's side to child, remove node

    if (valNode->left == nullptr || valNode->right == nullptr) {
        Node* child;
        //is valnode the root
        if (valNode == root) {
            if (root->left == nullptr) {
                root = root->right;
                root->parent = nullptr;
                valNode->right = nullptr;
                delete valNode;
                return true;
            } else {
                root = root->left;
                root->parent = nullptr;
                valNode->left = nullptr;
                delete valNode;
                return true;
            }
        }
        
        if (valNode->left == nullptr) {
            child = valNode->right;
        } else {
            child = valNode->left;
        }

        // if valnode is the left child itself
        // set the left child of parent of valnode to be valnodes og child
        if (valNode == valNode->parent->left) {
            valNode->parent->left = child;
            child->parent = valNode->parent;
        } 
        else {
            valNode->parent->right = child;
            child->parent = valNode->parent;
        }

        valNode->right = nullptr;
        valNode->left = nullptr;

        delete valNode;
        return true;
    }

    // case 3: node with two children
        // getSuccessor, copy succ to node, then remove succ (recursive-ish call)

    if (valNode->left && valNode->right) {
        VirtualCard succCard = getSuccessor(vCard.getSuit(), vCard.getValue());
        remove(succCard.getSuit(), succCard.getValue());
        valNode->nCard = succCard;
        return true;
    }

    return false;

}