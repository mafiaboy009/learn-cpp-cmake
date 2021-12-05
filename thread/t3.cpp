/*
 * Avoiding Data race:
 * 1. Use mutex to synchronize data access
 * 2. Never leak a handle of data to outside
 * 3. Design interface appropriately
 */
#include "thread.hpp"

int main(){

    cout << "main thread id: " << this_thread::get_id() << newLine;
    thread t1(function_3);
    for(int i=0;i<3;i++){
        shared_print(string("from main: "), i);
    }
    t1.join();

    thread t2(function_4);
    for(int i=0;i<3;i++){
        shared_print_exceptionSafe(string("from main: "), i);
    }
    t2.join();

    // build mutex into an object and never give access to internals 
    // directly
    LogFile log;
    thread t3(function_5, ref(log));
    for(int i=0;i<3;i++){
        log.shared_print_exceptionSafe(string("from main: "), i);
    }
    t3.join();

    myStack st1;
    thread t4(function_6, ref(st1));
    thread t5(function_6, ref(st1));
    thread t6(function_6, ref(st1));
    thread t7(function_6, ref(st1));
    thread t8(function_6, ref(st1));
    //thread t9(function_6, ref(st1));
    t6.join();
    t4.join();
    t5.join();
    t7.join();
    t8.join();
    //t9.join();
    
    myStackSync st2;
    thread t10(function_7, ref(st2));
    thread t11(function_7, ref(st2));
    thread t12(function_7, ref(st2));
    thread t13(function_7, ref(st2));
    thread t14(function_7, ref(st2));
    thread t15(function_7, ref(st2));
    t14.join();
    t13.join();
    t12.join();
    t11.join();
    t10.join();
    t15.join();


    return 0;
}
