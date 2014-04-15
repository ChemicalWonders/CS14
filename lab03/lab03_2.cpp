// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 4: Find nth node from tail end of singly linked list
#include <iostream>
#include <list>
using namespace std;

Node& getNodeFromTail(Node A, int x){
    int length = 0;
    Node temp = A;
    while(temp -> next != NULL){
        temp = temp->next;
        --length;
    }
    int a = --length;
    for(int beta = 0; beta < a; ++y){
        A = A->next;
    }
    return head;
}

int main(){
    list <int> A;
    int n = 0;
    int b = 0;
    
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    
    cout << "Which node would you like?" << endl;
    cin >> n;
    
    cout << "The list is: ";
    cout << endl;
    
    for (list<int>::iterator k = A.begin(); k != A.end(); ++k)
        cout << ' ' << *k;
    cout << endl;
    
    cout << "The number is:";
    b = A.size()-1;
    for (list<int>::iterator j = A.end(); j != A.begin(); --j){
        
        if ((b) == n){
            cout << " " << *j;
        }
        --b;
    }
    cout << endl;

    return 0;
}
