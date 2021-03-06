// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 3: Intersection between both lists

#include <iostream>
#include <list>

using namespace std;

int main(){
    
    list <int> L, P, both;
    
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    
    P.push_back(5);
    P.push_back(6);
    P.push_back(8);
    P.push_back(1);
    
    L.sort(); P.sort(); //Sorts both functions
    
    for (list<int>::iterator j = P.begin(); j != P.end(); ++j){
        for (list<int>::iterator i = L.begin(); i != L.end(); ++i){
            if ( *j == *i){
                both.push_front(*i);
            }
        }
    }
    both.sort();
    cout << "Both have:";
    for (list<int>::iterator k = both.begin(); k != both.end(); ++k)
        cout << ' ' << *k;
    cout << endl;
    
    return 0;
}
