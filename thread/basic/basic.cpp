#include "thread.hpp"

int main(){

    thread t1(function_1); // t1 starts running
    t1.detach(); // t1 will freely on its own i.e., daemon process
    //t1.join(); // main thread waits for t1 to finish

    thread t2(function_1); // t1 starts running
    t2.detach(); // t1 will freely on its own i.e., daemon process

    if( t1.joinable() ){
        t1.join(); // main thread waits for t1 to finish
    }
    
    return 0;
}
