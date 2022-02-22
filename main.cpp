#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// returns if there is a matching VirtualCard
bool hasMatch (VirtualCard firstCard, CardBST cardTree) {
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

  // while Alice's curr card is != final card 
  while (currCardA != maxCardA) {
    // Alice iterates in order thru her cards
  // if one of them has a match then the card is removed from
  // Alice's BST and Bob's BST
   

  // Bob iterates backwards thru his cards
  // if one of them has a match then the card is removed from
  // Alice and Bob's BSTs
  }
  
  
  return 0;
}
