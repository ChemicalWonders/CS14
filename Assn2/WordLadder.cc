#include <iostream>
#include <list>
#include <queue>
#include <fstream>
#include <stack>
#include <string>
#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string listFile){
    ifstream putWordsIntoDictionary;
    string word;
    
    putWordsIntoDictionary.open(listFile.c_str());
    
    if(!putWordsIntoDictionary.is_open()){
        cout << "Filename invalid or file is corrupted. \n";
        exit(1);
    }
    
    while (putWordsIntoDictionary >> word){
        dictionary.push_back(word);
    }
    
    putWordsIntoDictionary.close();
} 

void WordLadder::outputLadder(const string start, const string end){
    if(start == end){
        return;
    }
}
