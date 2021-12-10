/*
 * const_cast can also be used to cast away volatile attribute. 
 *
 * For example, in the following program, the typeid of b1 is PVKi (pointer to a volatile and constant integer) and 
 * typeid of c1 is Pi (Pointer to integer)
 *
 */

#include <iostream>
#include <typeinfo>

using namespace std;
  
int main(void)
{
    int a1 = 40;
    const volatile int *b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << '\n';
    int *c1 = const_cast<int*>(b1);
    cout << "typeid of c1 " << typeid(c1).name() << '\n';
    cout << "typeid of a1 " << typeid(a1).name() << '\n';
    return 0;
}
