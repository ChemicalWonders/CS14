#include <iostream>
#include "WordLadder.h"

using namespace std;

int main(int argc, char* argv []){
    //Checks for valid arguments argc and argv
    if(argc < 4){
        cout << "Not enough parameters, follow the format: ./a.out" <<
        " dictionary.txt word1 word2\n";
        exit(1);
    }
    
    //Changes argv into strings
    string dictionaryName = argv[1];
    string startWord = argv[2];
    string endWord = argv[3];
    
    //Creates the WordLadder with the default constructor
    WordLadder pass(dictionaryName);
    
    //Starts the program and outputs the WordLadder
    //pass.outputLadder(startWord, endWord);
    
    return 0;
}
