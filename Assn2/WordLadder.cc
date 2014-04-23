//=================================================================
// Course: CS 14 Spring 2014
//
// First name: Kevin
// Last name: Chan
// Course username: kchan039
// Email address: kchan039@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: John Cross
//
// Assignment: Word Ladder
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

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
    //Checking for vaild input words
    if (!validWord(start) || !validWord(end)){
        cout << "The words you entered do not exist in this dictionary."
        << "\nPlease try again. \n";
        exit(1);
    }
    
    //Checking if the same word is entered for start and end
    if(start == end){
        cout << start << endl;
        return;
    }
    
    //Create the stack of strings and queue up the first word
    stack <string> wordList;
    wordList.push(start);
    
    //Start the Queue of Stacks to hold everything
    queue < stack <string> > ladder;
    ladder.push(wordList);
    
    while(!ladder.empty()){
        for(list<string>::iterator i = dictionary.begin();
            i != dictionary.end(); ++i){
            
            if (differentByOne (ladder.front().top(), *i)){
                if (*i == end){
                    stack<string> output;
                    
                    while(!ladder.front().empty()) {
                        output.push(ladder.front().top());
                        ladder.front().pop();
                    }
                    
                    while (!output.empty() ) {
                        
                        cout << output.top() << " ";
                        output.pop();
                    }
                    cout << *i << endl;
                    return;
                }
            
                stack<string> temp = ladder.front();
                temp.push(*i);
                ladder.push(temp);
                dictionary.erase(i);
                --i;
            }
        }
        ladder.pop();
    }
}

bool WordLadder::validWord(const string& str){
    //Loops through the dictionary
    for (list<string>::iterator i = dictionary.begin();
    i != dictionary.end(); ++i){
        
        //If word exists, return true
        if (*i == str)
            return true;
    }
    return false;
}

bool WordLadder::differentByOne(const string &word, const string& secondWord){
    
    int count = 0;
    // If the position of the letters do not match, increment counter
    for (unsigned i = 0; i < word.size(); ++i){
        if (word.at(i) != secondWord.at(i)){
            ++count;
        }
    }
    //Return True ONLY IF THE COUNTER EQUALS 1
    if (count == 1)
        return true;
    
    return false;
}
