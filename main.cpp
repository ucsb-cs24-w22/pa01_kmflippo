#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

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
  
  
  return 0;
}
