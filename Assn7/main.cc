#include <iostream>
#include "prim.H"

using namespace std;

int main() {
    
    Graph alpha;
    
    Edge A(2,2,3);
    Edge B(5,3,7);
    Edge C;
    Edge D;
    Edge G(1,2,3);
    Edge H(7,4,5);
    Edge K(8,2,1);
    
    alpha.insert(A);
    alpha.insert(B);
    alpha.insert(C);
    alpha.insert(G);
    alpha.insert(H);
    alpha.insert(K);
    alpha.insert(D);
    
    prim(alpha);
    display(alpha);
  
  return 0;
}
