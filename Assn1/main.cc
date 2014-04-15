#include <iostream>
#include "Node.h"
#include "MyList.cc"

using namespace std;

int main(){
    MyList A;
    
    A.push_front('1');
    A.push_back('g');
    A.insert_at_pos(1, 'a');
    A.print();
    cout << "Size is " << A.size();
    cout << endl;

    //A.pop_front();
    A.push_back('j');
    A.swap(1,4);
    A.print();
    cout << "Size is " << A.size();
    cout << endl;
    cout << "Finding A at: " << A.find('g'); 
    cout << endl;
    
    MyList B = A;
    A.push_back('1');
    A.print();
    cout << endl;
    B.print();
    cout << endl;
    MyList C;
    C = A+B;
    C.print();
    cout << endl;
    cout << "at position c[2]: " <<  C[2];
    cout << endl;
	return 0;
}
