/*
 * unique_lock and lazy initializaion
 *
 * unique_lock
 * -- unique_lock<mutex> 
 * -- more flexibility, i.e., lock only when needed
 * -- we can lock and/or unlock when needed
 * -- unique_lock<mutex> locker1{m_me_1, defer_lock};
 *  -- locker1 is the owner of the mutex but not locked yet
 * -- lock_guard or unique_lock can NEVER be COPIED 
 * -- lock_guard can NEVER be MOVED
 * -- unique_lock can be COPIED 
 * -- unique_lock brings in overhead - affects performance 
 * -- prefer lock_guard if performance matters
 *
 * lazy initialization - Initialization Upon First Use Idiom
 * -- USE std::once_flag and std::call_once
 * -- efficient and accurate
 */

#include "thread.hpp"

int main(){
    cout << "main thread id: " << this_thread::get_id() << newLine;

    LogFileV5 log;
    thread t1(function_12, ref(log));
    cout << "t1 threadId: " << t1.get_id() << newLine;
    for(int i=0;i<10;i++){
        log.shared_print_exceptionSafe1(string("from main: "), i);
    }
    t1.join();

    LogFileV6 log1;
    thread t2(function_13, ref(log1));
    cout << "t2 threadId: " << t2.get_id() << newLine;
    for(int i=0;i<10;i++){
        log1.shared_print_exceptionSafe1(string("from main: "), i);
    }
    t2.join();

    return 0;
}
