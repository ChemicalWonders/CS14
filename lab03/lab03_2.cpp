// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 4: Find nth node from tail end of singly linked list
#include <iostream>
#include <list>
using namespace std;

int getNodeFromTail(int value, list<int> alpha){
    alpha.reverse();
    int a = alpha.size();
    for (list<int>::iterator f = alpha.begin(); f != alpha.end(); ++f){
    --a;
        if (value == a){
            return *f;
        }
    }
     return -1;
}
int main(){
    list <int> A;
    int n = 0;
    
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
    
    cout << getNodeFromTail(n,A);

    cout << endl;

    return 0;
}
