/*
 * Future and Promise
 * 
 * Future -- usually, used when child thread sends to parent thread
 * -- async( launch::defferred, function-name, params... )
 *  -- will execution of the function until future.get is called
 *  -- also main and function execution happens on the same thread
 *
 * -- async( launch::async, function-name, params... )
 *  -- will create another thread
 *
 * -- async( launch::async|launch::defferred, function-name, params... )
 *  -- depends on the implementation
 *  -- same as async( function-name, params... )
 *
 * -- each future can only call get() once
 * -- use shared_future
 * -- shared_future can be COPIED, so no need of reference
 *  -- can be used for broadcasting
 *
 * Promise -- usually, when parent want to communicate with child thread
 * -- if a promise is not kept then an exception is thrown
 * -- we can also pass an exception if a promise cannot be kept
 *
 * NOTE:
 * -- Neither future nor promise can be COPIED, only MOVED
 */
#include "thread.hpp"

int main(){

    thread t1( factorial_1, 4);
    t1.join();

    int fact{0};
    int number{5};
    thread t2( factorial_2, number, ref(fact));
    t2.join();
    // !! Warning !!fact should be set before we use it !!
    // so we need mutex and condition_variable for sync
    // SOLUTION: Use future and get
    cout << "[main] The factorial of " << number << " is " << fact << newLine;

    int number1{6};
    future<int> futureInt = async(factorial_3, number1);
    //NOTE: async is a function and it may or may not create another thread; 
    //this thread creation can be controlled
    int fact1 = futureInt.get(); // a blocking call???
    // calling futureInt.get() again will crash the program
    cout << "[main] The factorial of " << number1 << " is " << fact1 << newLine;


    int number2{7};
    promise<int> pro1;
    future<int> futureInt1 = pro1.get_future();
    future<int> futureInt2 = async(launch::async, factorial_4, ref(futureInt1));
    this_thread::sleep_for( chrono::milliseconds(20) );
    pro1.set_value( number2 ); // set exception if we cannot send a value
    //pro1.set_exception(make_exception_ptr(runtime_error("To err is human")));
    int fact2 = futureInt2.get(); // a blocking call???
    cout << "[main] The factorial of " << number2 << " is " << fact2 << newLine;

    // shared_future -- a broadcaster -- can be copied
    int number3{8};
    promise<int> pro2;
    future<int> futureInt3 = pro2.get_future();
    shared_future<int> sharedFuture1 = futureInt3.share();
    future<int> futureInt4 = async(launch::async, factorial_5, sharedFuture1 );
    future<int> futureInt5 = async(launch::async, factorial_5, sharedFuture1 );
    pro2.set_value( number3 ); // set exception if we cannot send a value
    return 0;
}
