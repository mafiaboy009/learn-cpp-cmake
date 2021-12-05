#include <iostream>

using namespace std;

extern const char newLine;
int i = 42;

int main(){
    int i = 56;
    cout << "[ local ] i is " << i << newLine;
    cout << "[ global] i is " << ::i << newLine;
    return 0;
}

