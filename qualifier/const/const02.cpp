/*
 * const and functions
 *
 * const T& -- const reference
 */
#include "const02.hpp"

int main(){

    cout << string(10,'*') << endl;
    Dog d;
    int i = 9;
    d.setAge(i); // this will call non-cont setAge()
    cout << i << endl;
    cout << d.getAge() << endl;
    const string& n = d.getName();
    cout << n << endl;
    d.printDogName();

    cout << string(10,'*') << endl;
    Dog ncd; // non-const dog
    ncd.setAge( 5 ); // this will call const setAge()
    ncd.printDogName();

    cout << string(10,'*') << endl;
    const Dog cd; // const dog
    //cd.setAge( 6 );
    cd.printDogName();

    return 0;
}
