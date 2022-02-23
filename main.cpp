#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// returns if there is a matching VirtualCard
bool hasMatch (VirtualCard firstCard, CardBST& cardTree) {
  if (cardTree.contains(firstCard.getSuit(), firstCard.getValue())) {
    return true;
  } else {
    return false;
  }
}

// returns if the trees have at least one card in common
bool treeMatch (CardBST& bst1, CardBST& bst2) {
  bool operator==(const VirtualCard& first, const VirtualCard& second);
  bool operator!=(const VirtualCard& first, const VirtualCard& second);

  VirtualCard emptyCard("0", 0);
  VirtualCard currCard = bst1.getMinCard();
  while (currCard != emptyCard) {
    if (hasMatch(currCard, bst2)) {
      return true;
    }
    currCard = bst1.getSuccessor(currCard.getSuit(), currCard.getValue());
  }
  return false;
}

// check forwards
VirtualCard forwardTurn (CardBST& bst1, CardBST& bst2) {
  bool operator==(const VirtualCard& first, const VirtualCard& second);
  bool operator!=(const VirtualCard& first, const VirtualCard& second);

  VirtualCard emptyCard("0", 0);
  VirtualCard currCard = bst1.getMinCard();
  while (currCard != emptyCard) {
    if (hasMatch(currCard, bst2)) {
      return currCard;
    }
    currCard = bst1.getSuccessor(currCard.getSuit(), currCard.getValue());
  }
}

// check backwards
VirtualCard backwardTurn (CardBST& bst1, CardBST& bst2) {
  bool operator==(const VirtualCard& first, const VirtualCard& second);
  bool operator!=(const VirtualCard& first, const VirtualCard& second);
  
  VirtualCard emptyCard("0", 0);
  VirtualCard currCard = bst1.getMaxCard();
  while (currCard != emptyCard) {
    if (hasMatch(currCard, bst2)) {
      return currCard;
    }
    currCard = bst1.getPredecessor(currCard.getSuit(), currCard.getValue());
  }
}

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //create alice bst and bob bst
  CardBST bstA, bstB;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    string mySuit = line.substr(0,1);
    string strVal = line.substr(2, line.length()-2);
    int value = 0;
    if (strVal == "a") {
        value = 1;
    } else if (strVal == "j") {
        value = 11;
    } else if (strVal == "q") {
        value = 12;
    } else if (strVal == "k") {
        value = 13;
    } else {
        value = stoi(strVal);
    }
    bstA.insert(mySuit, value);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    string mySuit = line.substr(0,1);
    string strVal = line.substr(2, line.length()-2);
    int value = 0;
    if (strVal == "a") {
        value = 1;
    } else if (strVal == "j") {
        value = 11;
    } else if (strVal == "q") {
        value = 12;
    } else if (strVal == "k") {
        value = 13;
    } else {
        value = stoi(strVal);
    }
    bstB.insert(mySuit, value);
  }
  cardFile2.close();

  // declare boolean operators 
  bool operator==(const VirtualCard& first, const VirtualCard& second);
  bool operator!=(const VirtualCard& first, const VirtualCard& second);

  bool aliceTurn = true;

  cout << " Alice in order: ";
        bstA.printInOrder();
        cout << endl << endl;
  cout << " Bob in order: ";
        bstB.printInOrder();
        cout << endl << endl;

  // while there is at least one match
  while (treeMatch(bstA, bstB)) {
    if (aliceTurn) {
      // check forward
      VirtualCard rCard = forwardTurn(bstA, bstB);
      bstA.remove(rCard.getSuit(), rCard.getValue());
      bstB.remove(rCard.getSuit(), rCard.getValue());
    } else {
      // check backward
      VirtualCard rCard = backwardTurn(bstB, bstA);
      bstA.remove(rCard.getSuit(), rCard.getValue());
      bstB.remove(rCard.getSuit(), rCard.getValue());
    }
  }

  cout << " Alice in order: ";
        bstA.printInOrder();
        cout << endl << endl;
  cout << " Bob in order: ";
        bstB.printInOrder();
        cout << endl << endl;
  
  
  return 0;
}
