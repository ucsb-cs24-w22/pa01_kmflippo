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

// returns 


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

  // find Alice's final card
  VirtualCard currCardA = bstA.getMinCard();
  VirtualCard maxCardA = bstA.getMaxCard();
  VirtualCard currCardB = bstB.getMaxCard();
  VirtualCard emptyCard("0", 0);
  bool aliceTurn = true;
  int iterations = 0;
  int origCount = bstA.count();

  // while Alice's curr card is != final card 
  bool operator==(const VirtualCard& first, const VirtualCard& second);
  bool operator!=(const VirtualCard& first, const VirtualCard& second);


  while (iterations <= origCount) {
    cout << " has match : " << hasMatch(currCardA, bstB) << endl;
    // Alice iterates in order thru her cards
    // if one of them has a match then the card is removed from
    // Alice's BST and Bob's BST
    // while (aliceTurn == true) {
      VirtualCard succCardA = bstA.getSuccessor(currCardA.getSuit(), currCardA.getValue());
      iterations++;
      if(hasMatch(currCardA, bstB)){
        bstA.remove(currCardA.getSuit(), currCardA.getValue());
        bstB.remove(currCardA.getSuit(), currCardA.getValue());
        // iterate
        currCardA = succCardA;
        cout << "Alice picked matching card " << currCardA.getSuit() << " " << currCardA.getValStr() << endl;
        aliceTurn = false;
      } else if (succCardA != emptyCard) {
        //iterate
        currCardA = succCardA;
      } else {
        cout << "alice turn is false " << endl;
        aliceTurn = false;
        currCardA = maxCardA;
      }
    // }
   

    // Bob iterates backwards thru his cards
    // if one of them has a match then the card is removed from
    // Alice and Bob's BSTs
    cout << " has match : " << hasMatch(currCardB, bstA) << endl;
    // while (aliceTurn == true) {
      iterations++;
      VirtualCard preCardB = bstB.getPredecessor(currCardB.getSuit(), currCardB.getValue());
      if(hasMatch(currCardB, bstA)){
        bstA.remove(currCardB.getSuit(), currCardB.getValue());
        bstB.remove(currCardB.getSuit(), currCardB.getValue());
        // iterate
        currCardB = preCardB;
        cout << "Bob picked matching card " << currCardB.getSuit() << " " << currCardB.getValStr() << endl;
        aliceTurn = true;
      } else if (preCardB != emptyCard) {
        //iterate
        currCardB = preCardB;
      } else {
        cout << "alice turn is false " << endl;
        aliceTurn = true;
        currCardA = maxCardA;
      }
    // }
    
  }

  cout << " Alice in order: ";
        bstA.printInOrder();
        cout << endl << endl;
  cout << " Bob in order: ";
        bstB.printInOrder();
        cout << endl << endl;
  
  
  return 0;
}
