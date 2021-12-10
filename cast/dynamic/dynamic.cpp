/*
 * Down cast
 * casting a dervied type to base type
 *
 * Up cast
 * casting a base type to derived type
 *
 * dynamic_cast - down cast
 *
 */

#include "dynamic.hpp"

int main(){

    /*
    dog *pd = new yellowdog(); // this is a static_cast
    
    yellowdog py = dynamic_cast<yellowdog*>(pd);
    //1. It convert pointer/reference from one type to a related type ( down cast )
    //2. run-time type check. If succeed, py == pd; if fail, py == nullptr
    //3. It requires the 2 types to be polymorphic ( have virtual function )
*/

    // yellowdog is a dog
    // but all dogs are not yellowdog

    cout << string(10, '*') << endl;
    dog *pd0 = new dog();
    yellowdog *py0 = dynamic_cast<yellowdog*>(pd0); // a dog is not necessarily a yellow dog; NOT success
    //yellowdog *py0 = static_cast<yellowdog*>(pd0); // success because of NO type check; if you call bark() with this then behaviour is undefined
    py0->bark(); // this will work - A BUG - this line will give a segv if the bark() used a data member
    cout << "py0 is " << py0 << endl;
    cout << "pd0 is " << pd0 << endl;

    cout << string(10, '*') << endl;
    yellowdog *py1 = new yellowdog();
    dog *pd1 = dynamic_cast<dog*>(py1); // down cast is a success
    py1->bark();
    //pd1->bark(); // class dog has no bark()
    cout << "py1 is " << py1 << endl;
    cout << "pd1 is " << pd1 << endl;

    cout << string(10, '*') << endl;
    yellowdog *py2 = new yellowdog();
    dog *pd2 = dynamic_cast<dog*>(py2); // yellow dog is a dog
    yellowdog *py3 = dynamic_cast<yellowdog*>(pd2); // this dog is an yellowdog; success
    py2->bark();
    py3->bark();
    cout << "py2 is " << py2 << endl;
    cout << "py3 is " << py3 << endl;
    cout << "pd2 is " << pd2 << endl;

    // to avoid warning only -- you can ignore this space
    int a = py2->age;
    ++a;

    delete py1;
    delete py2;
    delete pd0;

    return 0;
}
