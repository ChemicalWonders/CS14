#include <iostream>
// Problem # 3
int odd_digits(int number){
    int odd = 0;
    
    if (number < 10){
        if (number%2 == 1){
            odd += 1;
        }
        return odd;
    }
    int digit = number % 10;
    if (digit%2 == 1){
        odd += 1;
    }
        
    return odd + odd_digits(number/10);
}

int main(){
    int A;
    
    std::cout << "Enter a number: ";
    std::cin >> A;
    std::cout << std::endl;
    
    std::cout << "The number of odd digits is: " << odd_digits(A);
    
    return 0;
}
