// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 3: Recurvsively reverse linked list
#include <iostream>
#include "MyList.h"

using namespace std;

//Reverse code in MyList.cc

//Reverses the items in the list.
//void reverse(){
    //reverse(head);
//}

////Private Helper Function for reverse()
//Node* reverse(Node * n){
    //if (n == 0){
        //return 0;
    //}
    //else if (n->next == 0){
        //head->next = 0;
        //head = n;
        //return n;
    //}
    //else{
        //reverse(n->next)->next  = n;
        //return n;
    //}
//}

int main(){
    MyList alpha;
    alpha.push_back('1');
    alpha.push_back('2');
    alpha.push_back('3');
    
    cout << "Original list: ";
    alpha.print();
    cout << endl;
    
    alpha.reverse();
    
    cout << "Reversed list: ";
    alpha.print();
    cout << endl;

    return 0;
}
