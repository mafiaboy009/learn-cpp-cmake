/*
 * Deadlock:
 * To avoid deadlock
 * -- prefer locking single mutex
 * OR
 * -- avoid locking a mutex and then calling a user provided function
 * OR
 * -- use std::lock() to lock more than one mutex
 * OR
 * -- Lock the mutex in same order
 *
 * Locking Granularity:
 * -- Fine-grained lock: protects small amount of data
 *  => deadlock can happen often
 * -- Coarse-grained lock: protects big amount of data
 *  => other threads are going to wait affecting parallelism
 */
 
#include "thread.hpp"


int main(){
    cout << "main thread id: " << this_thread::get_id() << newLine;

    /*
    //execution will result in deadlock
    LogFileV1 log;
    thread t1(function_8, ref(log));
    for(int i=0;i<10000;i++){
        log.shared_print_exceptionSafe1(string("from main: "), i);
    }
    t1.join();
    */

    LogFileV2 log1;
    thread t2(function_9, ref(log1));
    for(int i=0;i<10000;i++){
        log1.shared_print_exceptionSafe1(string("from main: "), i);
    }
    t2.join();

    LogFileV3 log3;
    thread t3(function_10, ref(log3));
    for(int i=0;i<10000;i++){
        log3.shared_print_exceptionSafe1(string("from main: "), i);
    }
    t3.join();

    return 0;
}
