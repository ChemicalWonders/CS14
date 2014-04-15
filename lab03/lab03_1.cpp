// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 3: Recurvsively reverse linked list
#include <iostream>
#include <list>

using namespace std;

list<int> reversed_list;
list<int> alpha;

void reversal(){
    if (alpha == NULL){
        return;
    }
    reversed_list.push_back(reversal(alpha->next));
}


int main(){
    
    alpha.push_back(1);
    alpha.push_back(2);
    alpha.push_back(3);
    
    reversal();
    
    for (list<int>::iterator j = alpha.begin(); j != alpha.end(); ++j)
        cout << ' ' << *j;
    cout << endl;

    return 0;
}
