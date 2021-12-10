/*
 * const_cast
 * - only works on pointer/reference
 * - only works on same type
 * - cast away constness of the object
 * - being pointed to
 */

#include <iostream>

using namespace std;

int main(){
    const char *str = "Hello, World!";
    char *modifiable = const_cast<char*>( str );
    cout << str << '\n';
    cout << modifiable << '\n';
    modifiable = "Hello, C++!";
    /*
    modifiable[7] = 'C';
    modifiable[8] = '+';
    modifiable[9] = '+';
    modifiable[10] = '\0';
    */
    cout << str << '\n';
    cout << modifiable << '\n';
}

