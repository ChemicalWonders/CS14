#ifndef __WORDLADDER_H_
#define __WORDLADDER_H_

#include <iostream>
#include <list>
#include <string>

using namespace std;

class WordLadder{
    private:
        list<string> dictionary;
        
    public:
        // Constructor that passes in the name of the dictionary file
        WordLadder(const string listFile);
        
        // Passes in the start and end words and outputs 
        // to standard output the word ladder
        void outputLadder(const string start, const string end);
    };
        
#endif
