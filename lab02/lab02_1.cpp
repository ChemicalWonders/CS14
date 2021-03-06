// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 6: Computing L1 U L2 using only basic list operations
#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> ListNum1, ListNum2;

    ListNum1.push_back(1);
    ListNum1.push_back(2);
    ListNum1.push_back(3);

    ListNum2.push_back(1);
    ListNum2.push_back(3);
    ListNum2.push_back(5);

    ListNum1.merge(ListNum2);
    ListNum1.unique();

    cout << "ListNum1 contains: ";
    for (list<int>::iterator i = ListNum1.begin(); i != ListNum1.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    return 0;
}
