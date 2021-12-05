/*
 * Packaged Tasks
 * -- a packaged object can link a callable object with future
 * -- this is not possible in std::bind()
 * 
 * Bind function
 * -- returns a function object
 *
 * Three ways to get a future:
 * -- promise::get_future()
 * -- packaged_task::get_future()
 * -- async() returns a future
 */

#include "thread.hpp"

int main(){

    int number1{6};
    packaged_task<int(int)> t1( factorial_6 );
    t1(number1);
    int ret1 = t1.get_future().get();
    cout << "[main] factorial of " << number1 << " is " << ret1 << newLine;

    int number2{8};
    //packaged_task<int(int)> t2( bind(factorial_6, number2) );
    //packaged_task<int(int)> t2( function_object  );
    packaged_task<int()> t2( bind(factorial_6, number2) );
    t2();
    //t2(number1);
    int ret2 = t2.get_future().get();
    cout << "[main] factorial of " << number2 << " is " << ret2 << newLine;

    int number3{9};
    thread t3(thread_1);
    packaged_task<int()> t4( bind(factorial_6, number3) );
    future<int> futureInt1 = t4.get_future();
    {
        lock_guard<mutex> locker{t9Mutex};
        taskQue.push_back( move(t4) );
    }
    t9Cond.notify_one();
    int ret3 = futureInt1.get();
    cout << "[main] factorial of " << number3 << " is " << ret3 << newLine;
    t3.join();

    return 0;
}
