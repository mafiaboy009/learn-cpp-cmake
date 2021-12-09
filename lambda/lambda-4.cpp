#include "lambda.hpp"

int main(){

    int a{5};
    char b{'c'};
    string d{"lambda"};

    auto function = [&]( int scale ) noexcept {
        cout << "lamdba says" << newLine;
        cout << "int " << a+scale << newLine;
        cout << "char " << b << newLine;
        cout << "string " << d << newLine;
        a = 10 + scale;
        b = 'd';
        d = "expression";
    };

    function(2);

    cout << string( 10, '*') << newLine;
    cout << "main says" << newLine;
    cout << "int " << a << newLine;
    cout << "char " << b << newLine;
    cout << "string " << d << newLine;

    return 0;
}

