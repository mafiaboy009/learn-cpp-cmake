/*
 * Why use const?
 * -- Guards against inadevertent write to the variable
 * -- Self documenting
 * -- Enables compiler to do more optimization, making code tighter
 * -- const means the variable can be put in ROM
 *
 * Thumb rule
 * -- if const is on the left of *, then data is const
 * -- if const is on the right of *, then pointer is const
 *
 * Using cast
 * -- we can cast away const-ness of a data
 *
 */
#include <iostream>

using namespace std;

int main(){
    const int i = 9;
    // i = 6; // compiler err

    const int *p1 = &i; // data is constant, pointer is not
    p1++; // pointer is not constant so we can modify

    int k{10};
    int* const p2 = &k;// pointer is const, data is not

    const int* const p3 = &i; // data and pointer are constant

    // following two statements are equivalent;
    int const *p4 = &i; // 
    //const int *p4 = &i; // 

    // casting const-ness away
    const int j = 9;
    const int *pJ = &j;
    cout << "j " << j << '\n';
    const_cast<int&>(j) = 6;
    cout << "j " << j << '\n';
    cout << "j " << *pJ << '\n';
    
    // non-const to const
    int m{10};
    int *ptr = &m;
    cout << "m " << m << '\n';
    static_cast<const int&>(m); // has no effect?
    // static_cast<const int&>(m) = 7; // compile err
    m = 7;
    cout << "m " << m << '\n';
    *ptr = 8;
    cout << "*ptr " << *ptr << '\n';

    return 0;
}
