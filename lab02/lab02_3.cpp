// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 3: Copying a list L into another list P by only traversing L once.

#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> L, P;
    // Adding some data point into the list
    L.push_back(100);
    L.push_back(15);
    L.push_back(17);
    L.push_back(1);
    
    L.sort(); // SORTED LIST:Comment it out if you want to test NON-SORTED
    
    //Reversing the List
    for (list<int>::iterator i = L.begin(); i != L.end(); ++i){
        P.push_front(*i);
    }
    
    //Printing it out! I have to tranverse the list to print them out.
    
    cout << "J: ";
    for (list<int>::iterator k = L.begin(); k != L.end(); ++k)
        cout << ' ' << *k;
    cout << endl;
    
    cout << "P: ";
    for (list<int>::iterator j = P.begin(); j != P.end(); ++j)
        cout << ' ' << *j;
    cout << endl;
    
    return 0;
    
}
