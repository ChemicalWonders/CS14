// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 5: Printing P numbers for L

#include <iostream>
#include <list>


using namespace std;

void printLots (list<int> L, list<int> P)
{
    P.sort(); // Sorts the list from smallest to biggest.
    P.unique(); //Removes any duplicates; Linear time.
    
    list <int> combine;
    
    int counter = 0;
    
    for (list<int>::iterator j = P.begin(); j != P.end(); ++j){
        counter = 0;
        for (list<int>::iterator i = L.begin(); i != L.end(); ++i){
            if ( *j == counter){
                combine.push_front(*i);
            }
            counter++;
        }
    }
    combine.sort();
    cout << "P(L) =";
    for (list<int>::iterator k = combine.begin(); k != combine.end(); ++k)
        cout << ' ' << *k;
    cout << endl;
    return;
    
    //Total time for function: O(n^2) 
    //It's a horrible function, but it works!
}


int main()
{
    list <int> alpha, beta;
    alpha.push_back(1);
    alpha.push_back(2);
    alpha.push_back(3);
    
    beta.push_back(2);
    beta.push_back(1);
    
    printLots(alpha, beta);
    
    return 0;
}
