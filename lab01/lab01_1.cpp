#include <iostream>

//Problem #4

int main(){
    int a, b = 0;
    
    std::cout << "Enter a integer: ";
    std::cin >> a;
    std::cout << std::endl;
    
    std::cout << "Enter another integer: ";
    std::cin >> b;
    std::cout << std::endl;
    
    std::cout << "Your current numbers are A: " << a << " and B: " << 
    b << ".\n";
    // Implemented a simple algorithm in swapping
    a = a+b;
    b = a-b;
    a = (a-b);
    
    std::cout << "Your numbers are now reversed.\n";
    std::cout << "A is " << a << " and B is " << b;
    std::cout << std::endl;
    
    return 0;
}
