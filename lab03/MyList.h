//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment01/MyList.cc
/// @brief Assignment 1 for CS 14 Spring 2014
///
/// @author Kevin Chan [kchan039@ucr.edu]
/// @date April 15, 2014
///
/// @par Enrollment Notes 
///     Lecture Section: 01
/// @par
///     Lab Section: 21
/// @par
///     TA: John Cross
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================
#ifndef __MYLIST_H_
#define __MYLIST_H_

#include <iostream>
#include <string>
#include "Node.h"

class MyList{
	private:
		Node* head;
        
        //Private Helper Function
        Node* reverse(Node * n);
	public:
		MyList();
		//Default Constructor

		MyList(const MyList & str);
		// Constructs a list from a passed-in MyList Object, e.g. MyList list1(list2)

		MyList(const char* str);
		//Constructs a list from a passed-in string literal, e.g. MyList list1("Hello World");

		~MyList();
		// Destructor

		//Mutators
		void push_front(char value);
		//Inserts value at the front of the list

		void push_back(char value);
		//Inserts value at the back of the list
		
		void pop_front();
		//Removes the front item from the list
		
		void pop_back();
		//Removes the last item from the list
		
		void swap(int i, int j);
		//Swaps the value of the node at position i in the list
		//with the value of the node at position j
		//HANDLE OUT-OF-RANGE CALLS

		void insert_at_pos(int i, char value);
		//Inserts a node with value at position i in the list

		void reverse();
		//Reverses the items in the list.

		//Accessors
		int size() const;
		//Returns the number of nodes in the list;

		void print() const;
		//Prints the contents of the list

		int find(char value) const;
		//Finds the position of the first occurrence of a char value in the list
		//and returns that position. If the character is not in the list, 
		//the function returns -1.

		int find(MyList& query_str) const;
		// Finds the position of the first occurance of the MyList query_str
		// in the list and returns that position. If query_str is not in the list
		//the function returns -1.

		//Operator Overloaders
		MyList& operator=(const MyList& str);
		//For assignment of one list to another, i.e. 11=12;

		char& operator[] (const int i);
		//Returns the character at position i

		MyList& operator+(const MyList& str);
		//Concatenates two list together, e.g. 11+ 12;
        
        //MyList& operator-(const MyList& str);
        //Subtracts from each list if they have the same value;
	};

#endif
