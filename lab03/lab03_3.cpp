// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 1: split list in the middle of L
#include <iostream>
#include <list>
using namespace std;

void splitDownMiddle(list<int> a, list <int>& b, list<int>& c){
    if (a.size() == 0)
        return;
    
    int num = a.size()/2;
    int number = 0;
    
    for (list<int>::iterator k = a.begin(); k != a.end(); ++k){
        if(num <= number){
            c.push_back(*k);
            cout << "C contains:";
            cout << " " << *k;
        }
        if(num > number){
            b.push_back(*k);
            cout << "B contains:";
            cout << " " << *k;
        }
        number++;
        
        cout << endl;
    }
}


int main(){
    list <int> A(6,100);
    list <int> B;
    list <int> C;
    
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    
    A.sort();
    
    cout << "A contains";
    for (list<int>::iterator k = A.begin(); k != A.end(); ++k)
        cout << " " << *k;
    cout << endl;
    
    splitDownMiddle(A,B,C);
    
    cout << "A contains";
    for (list<int>::iterator k = A.begin(); k != A.end(); ++k)
        cout << " " << *k;
    cout << endl;
    
    cout << "B contains";
    for (list<int>::iterator k = B.begin(); k != B.end(); ++k)
        cout << " " << *k;
    cout << endl;
    
    cout << "C contains";
    for (list<int>::iterator k = C.begin(); k != C.end(); ++k)
        cout << " " << *k;
    cout << endl;
    
    
    return 0;
}


