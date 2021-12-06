#include "myStack.hpp"
#include <gtest/gtest.h>

int main(){
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << myStack.toString() << newLine;

    cout << myStack.top() << newLine;
    myStack.pop();

    cout << myStack.top() << newLine;
    myStack.pop();

    cout << myStack.top() << newLine;
    myStack.pop();

    cout << myStack.top() << newLine;
    myStack.pop();

    cout << myStack.top() << newLine;
    myStack.pop();

    cout << myStack.toString() << newLine;

    return 0;
}
