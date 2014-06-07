#include "hashmap.H"
#include <iostream>
#include <cstdlib> 
#include <string>

using namespace std;

int main(){
    hashMap< int > alpha;
    Node <int> hello(5);
    Node <int> goodbye(2);
    alpha["5"] = hello;
    cout << alpha["0"] << endl;
    alpha.display();
    cout << endl;
    hashMap< int > beta(alpha);
    hashMap< int > omega = alpha;
    
    //alpha["56"] = goodbye;
    
    cout << omega["5"] << endl;
    alpha["5"] = goodbye;
    beta ["mysister"] = goodbye;
    omega.display();
    cout << endl;
    alpha.display();
    cout << endl;
    beta.display();
    cout << endl;
    return 0;
}
