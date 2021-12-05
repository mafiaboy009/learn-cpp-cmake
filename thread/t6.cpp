/*
 * Condition Variables
 *
 * Spurious Wake
 * -- a thread waking up by itself
 * -- predicates determine whether the thread should run or sleep
 */

#include "thread.hpp"

int main(){
    thread t1( function_14 );
    thread t2( function_15 );
    t1.join();
    t2.join();
    return EXIT_SUCCESS;
}
