#include "lambda.hpp"

int main(){

    int a{5};
    char b{'c'};
    string d{"lambda"};

    auto function = [&]() {
        cout << "lamdba says" << newLine;
        cout << "int " << a << newLine;
        cout << "char " << b << newLine;
        cout << "string " << d << newLine;
        a = 10;
        b = 'd';
        d = "expression";
    };

    function();

    cout << string( 10, '*') << newLine;
    cout << "main says" << newLine;
    cout << "int " << a << newLine;
    cout << "char " << b << newLine;
    cout << "string " << d << newLine;

    return 0;
}

