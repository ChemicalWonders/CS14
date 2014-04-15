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
#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

using namespace std;

struct Node {
		char value;
		Node* next;
		Node(): value(), next (0){};
		Node(char a): value(a), next(0){};
};
#endif
