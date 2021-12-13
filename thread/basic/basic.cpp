/*
 * Oversubscription - number of threads by app is greater than total number of threads supported by CPU
 *
 */

#include "basic.hpp"

int main(){

    //indicates the max# threads 
    cout << "MAX# threads: "<< thread::hardware_concurrency() << '\n'; 
    cout << "main thread id: " << this_thread::get_id() << "\n";

    thread t7(function_1); // t7 starts running
    t7.detach(); // t7 will freely on its own i.e., daemon process
    //t7.join(); // main thread waits for t7 to finish

    thread t8(function_1); // t8 starts running
    t8.detach(); // t8 will freely on its own i.e., daemon process

    if( t7.joinable() ){
        t7.join(); // main thread waits for t1 to finish
    }

    thread t1(function_1); // t1 starts running
    try{
        for(int i=0; i<3; i++){
            cout << "from main: " << i << '\n';
        }
    }
    catch(...){
        t1.join(); // ensure thread is joined before exception
        throw;
    }
    cout << "t1 thread id: " << t1.get_id() << "\n";
    t1.join(); // main thread waits for t1 to finish -- use join in a try-catch block


    Functor1 ftor;
    // try - catch has a better alternative using RAII - Wrapper w(t1) -- w's destructor should have t1.join
    thread t2(ftor); // t2 starts running
    cout << "t2 thread id: " << t2.get_id() << "\n";
    t2.join(); // main thread waits for t1 to finish -- use join in a try-catch block

    //thread t3(Functor1()); // compile err
    thread t3((Functor1())); // t2 starts running
    cout << "t3 thread id: " << t3.get_id() << "\n";
    t3.join(); // main thread waits for t1 to finish -- use join in a try-catch block

    string str1{"Where there is no trust, there is no love"};
    thread t4((Functor2()), str1); // t2 starts running
    cout << "t4 thread id: " << t4.get_id() << "\n";
    t4.join(); // main thread waits for t1 to finish -- use join in a try-catch block

    string str2{"Where there is no trust, there is no love"};
    thread t5((Functor3()), ref(str2)); // t2 starts running
    cout << "t5 thread id: " << t5.get_id() << "\n";
    t5.join(); // ensure thread is joined before exception
    cout << "from main: " << str2 << '\n';

    string str3{"Where there is no trust, there is no love"};
    thread t6((Functor2()), move(str3)); // t2 starts running
    cout << "t6 thread id: " << t6.get_id() << "\n";
    t6.join(); // ensure thread is joined before exception

    return 0;
}
