#include <iostream>
//Problem # 6
int program(int num){
    if (num == -2)
        return 0;
    
    return num*num*num + 4* program(num -1);
}

int main(){
    int A, B;
    
    std::cout << "Enter a number: ";
    std::cin >> A;
    std::cout << std::endl;
    
    B = program(A);
    
    std::cout << "This is the result of f(x) is " << B;
    std::cout << std::endl;
    return 0;
}
