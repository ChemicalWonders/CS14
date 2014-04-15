#include <iostream>
//Problem # 5
int series_program(int number){
    int i = 1;
    int j = 2;
    int product = 0;
    if (number == 1)
    {
        std:: cout << 1;
        return 1;
    }
    
    while (number > product){
        std::cout << i << " ";
        product = i * j;
        i = j;
        j = product;
    }
    std::cout << i << " " <<  j;
}

int main(){
    int A;
    
    std::cout << "Enter a postive integer: ";
    std::cin >> A;
    std::cout << std::endl;
    
    series_program(A);
    
    return 0;
}
