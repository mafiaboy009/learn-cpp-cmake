/*
 * Using Callable Objects
 *
 */

#include "thread.hpp"

int main(){

    A a;
    //1. two different ways of launching thread 
    thread t1( a, 6);
    async( launch::async, a, 6);
    //bind( a, 6);
    //call_once( onceFlag, a, 6);
    //2. four functions with same signature
    t1.join();

    thread t2( a, 6); // a copy of 'a' is created and invoked as a functor
    thread t3( ref(a), 6); // same 'a' is invoked as a functor
    thread t4( A(), 6); // temp A is created; the temp object is moved to the thread
    thread t5( &A::f, a, 7, 'w'); // a copy of 'a' is created and f is invoked
    a.id = 207;
    thread t6( &A::f, &a, 7, 'w'); // a copy of 'a' is created and f is invoked
    a.id = 306;
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    //thread t7( &A::f, move(a), 7, 'w');
    thread t7( move(a), 7);
    a.id = 405;
    t7.join();
    a(10);

    thread t10( [](int x){cout << "Square is " << x*x << newLine; }, 6);
    t10.join();

    thread t11( cube<float>, 6.0);
    t11.join();

    thread t12( cube<int>, 2);
    t12.join();

    return 0;
}
