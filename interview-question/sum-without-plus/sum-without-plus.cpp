#include <iostream>

int addWithoutPlus(int& op1, int& op2){
    while( op2 != 0 ){
        unsigned carry = op1 & op2;
        op1 = op1 ^ op2;
        op2 = carry << 1;
    }
    return op1;
}

int main(){
    int op1{0}, op2{0};
    while( true ){
        std::cout << "Enter operands: " << '\n';
        std::cin >> op1;
        std::cin >> op2;
        std::cout << "Sum is: " << addWithoutPlus(op1,op2) << '\n';
    }
    return EXIT_SUCCESS;
}
