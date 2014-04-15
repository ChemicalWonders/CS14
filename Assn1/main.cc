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
#include <iostream>
#include "Node.h"
#include "MyList.cc"

using namespace std;

int main(){
    MyList A;
    
    A.push_front('1');
    A.push_back('g');
    A.insert_at_pos(1, 'a');
    A.print();
    cout << "Size is " << A.size();
    cout << endl << "endl" << endl;

    A.push_back('j');
    A.swap(1,3);
    A.print();
    //~ cout << "second endl" << endl;
    cout << "Size is " << A.size();
    cout << endl;
    cout << "Finding A at: " << A.find('g'); 
    cout << endl;
    
    MyList B = A;
    A.push_back('1');
    A.print();
    cout << endl;
    
    B.print();
    cout << endl;
    
    MyList C;
    C = A+B;
    C.reverse();
    C.print();
    cout << endl;
    
    cout << "at position c[2]: " <<  C[2];
    cout << endl;
    
    MyList alpha(B);
    alpha.push_front('1');
    alpha.push_front('2');
    cout << "alpha.find(B) returns: " << alpha.find(B) << endl;
    
	return 0;
}
