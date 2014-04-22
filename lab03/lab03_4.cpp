// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 5: Circular Linked List
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
    list<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    
    //A.end() = A.begin();
    for (list<int>::iterator f = A.begin(); f != A.end(); ++f){
        if(A.end() == A.begin()){
            cout << "LIST IS CIRCULAR! EXITING NOW!" << endl;
            exit(1);
        }
    }
    cout << "List is not circular! Returning to main program" << endl;

    return 0;
}
    
    
