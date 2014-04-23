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

#ifndef __WORDLADDER_H_
#define __WORDLADDER_H_

#include <iostream>
#include <list>
#include <string>

using namespace std;

class WordLadder{
    private:
        list<string> dictionary;
        
        //Checks if the word that you are using is valid or not
        bool validWord(const string& valid);
        
        //Checks if the word is different by one from the original word
        bool differentByOne(const string& word, const string& secondWord);
        
    public:
        // Constructor that passes in the name of the dictionary file
        WordLadder(const string listFile);
        
        // Passes in the start and end words and outputs 
        // to standard output the word ladder
        void outputLadder(const string start, const string end);
    };
        
#endif
