#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <future> // future and promise

#include <fstream>
#include <array>
#include <stdexcept> // exception
#include <queue>

#include <functional> // bind

using namespace std;

const char newLine = '\n';
mutex me;

void delay(unsigned int factor=1){
    int i{0};
    int m_delay = factor*1000000;
    while(i<m_delay){ i++; }
}

template <typename A, typename B>
void shared_print(A a, B b){
    me.lock(); // not good - exception is handled
    cout << "thread id: " << this_thread::get_id() << newLine;
    cout << a << " " << b << newLine;
    me.unlock();
}

template <typename A, typename B>
void shared_print_exceptionSafe(A a, B b){
    lock_guard<mutex> guard(me); //even if exception -- destructor will unlock the mutex
    cout << "thread id: " << this_thread::get_id() << newLine;
    cout << a << " " << b << newLine;
    // cout is a global and it can be accessed from anywhere - bypassing the mutex
    // solution: bind mutex and the resource it is protecting
}

template <typename A, typename B>
void shared_print_exceptionSafe_delayed(A a, B b){
    delay(2);
    lock_guard<mutex> guard(me); //even if exception -- destructor will unlock the mutex
    cout << "thread id: " << this_thread::get_id() << newLine;
    cout << a << " " << b << newLine;
    // cout is a global and it can be accessed from anywhere - bypassing the mutex
    // solution: bind mutex and the resource it is protecting
}

void function_1(){
    cout << "Beauty is only skin-deep\n";
}

void function_2(){
    for( int i=0; i>-3; i--){
        cout << "from function_2: " << i << newLine;
    }
}

void function_3(){
    for( int i=0; i>-3; i--){
        shared_print( string("from function_3: "), i);
    }
}

void function_4(){
    for( int i=0; i>-3; i--){
        shared_print_exceptionSafe( string("from function_4: "), i);
    }
}

class Functor1{
    public:
        void operator()(){
            for( int i=0; i>-3; i--){
                cout << "from Functor1: " << i << '\n';
            }
        }
};

class Functor2{
    public:
        void operator()(string msg){
            cout << "Functor2 says: " << msg << '\n';
        }
};

class Functor3{
    public:
        void operator()(string& msg){
            cout << "Functor3 says: " << msg << '\n';
            msg = "Trust in the mother of deceit";
            cout << "Functor3 says: " << msg << '\n';
        }
};

class LogFile{
    //things never do
    //like., never return f to the outside world
    //ofstream& getStream() { return f; }
    //Never pass f as an arguement to a user provided function
    //void processf(void fun(ofstream&)){ fun(f); }
    mutex m_mutex;
    ofstream f;
    public:
    LogFile(){
        f.open("log.txt");
    } 
    void shared_print_exceptionSafe(string sender, int info){
        lock_guard<mutex> locker{m_mutex};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }
    ~LogFile(){
        f.close();
    }
};

void function_5(LogFile& log){
    for( int i=0; i>-3; i--){
        log.shared_print_exceptionSafe( string("from function_5: "), i);
    }
}

class myStack{
    array<int,5> m_data;
    mutex m_me;
    unsigned int m_top;
    public:

    myStack():m_data{1,2,3,4,5},m_top{5}{}

    void pop(){
        lock_guard<mutex> locker{m_me};
        if( m_top==0 ){
            cout << "myStack says stack is Empty!!" << newLine;
        }
        else{
            m_top=m_top-1;
        }
    }

    int& top(){
        lock_guard<mutex> locker{m_me};
        if( m_top==0 ){
            throw runtime_error( "myStack says stack is Empty!!" );
            // runtime_error, range_error, overflow_error, logic_error
        }
        return m_data[m_top-1];
    }
    
    // two separate interface, top and pop will cause issue
    // better keep only one interface which does both pop and top
};

void function_6( myStack& st ){
    int v = st.top();
    delay(2);
    st.pop();
    delay(2);
    shared_print_exceptionSafe_delayed("from function_6 ",v);
}

class myStackSync{

    array<int,5> m_data;
    mutex m_me;
    unsigned int m_top;

    public:

    myStackSync():m_data{1,2,3,4,5},m_top{5}{}

    int& topop(){
        lock_guard<mutex> locker{m_me};
        if( m_top==0 ){
            throw runtime_error( "myStack says stack is Empty!!" );
            // runtime_error, range_error, overflow_error, logic_error
        }
        m_top=m_top-1;
        return m_data[m_top];
    }
};

void function_7( myStackSync& st ){
    try{
        int v = st.topop();
        delay(2);
        shared_print_exceptionSafe_delayed( "from function_7 ", v );
    }
    catch(runtime_error err){
        cerr << "from function_7: " << err.what() << newLine;
    }
}

class LogFileV1{
    //things never do
    //like., never return f to the outside world
    //ofstream& getStream() { return f; }
    //Never pass f as an arguement to a user provided function
    //void processf(void fun(ofstream&)){ fun(f); }
    mutex m_me_1;
    mutex m_me_2;
    ofstream f;
    public:

    LogFileV1(){
        f.open("log.txt");
    } 

    void shared_print_exceptionSafe1(string sender, int info){
        lock_guard<mutex> locker1{m_me_1};
        lock_guard<mutex> locker2{m_me_2};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        lock_guard<mutex> locker2{m_me_2};
        lock_guard<mutex> locker1{m_me_1};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    ~LogFileV1(){
        f.close();
    }
};

void function_8(LogFileV1& log){
    for( int i=0; i>-10000; i--){
        log.shared_print_exceptionSafe2( string("from function_8: "), i);
    }
}

class LogFileV2{
    //things never do
    //like., never return f to the outside world
    //ofstream& getStream() { return f; }
    //Never pass f as an arguement to a user provided function
    //void processf(void fun(ofstream&)){ fun(f); }
    mutex m_me_1;
    mutex m_me_2;
    ofstream f;
    public:

    LogFileV2(){
        f.open("log.txt");
    } 

    void shared_print_exceptionSafe1(string sender, int info){
        lock_guard<mutex> locker1{m_me_1};
        lock_guard<mutex> locker2{m_me_2};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        lock_guard<mutex> locker1{m_me_1};
        lock_guard<mutex> locker2{m_me_2};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    ~LogFileV2(){
        f.close();
    }
};

void function_9(LogFileV2& log){
    for( int i=0; i>-10000; i--){
        log.shared_print_exceptionSafe2( string("from function_9: "), i);
    }
}

class LogFileV3{
    mutex m_me_1;
    mutex m_me_2;
    ofstream f;
    public:

    LogFileV3(){
        f.open("log.txt");
    } 

    void shared_print_exceptionSafe1(string sender, int info){
        lock( m_me_1, m_me_2);
        lock_guard<mutex> locker1{m_me_1, adopt_lock};
        lock_guard<mutex> locker2{m_me_2, adopt_lock};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        lock( m_me_1, m_me_2);
        lock_guard<mutex> locker2{m_me_2, adopt_lock};
        lock_guard<mutex> locker1{m_me_1, adopt_lock};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    ~LogFileV3(){
        f.close();
    }
};

void function_10(LogFileV3& log){
    for( int i=0; i>-10000; i--){
        log.shared_print_exceptionSafe2( string("from function_10: "), i);
    }
}

class LogFileV4{
    mutex m_me_1;
    mutex m_me_2;
    ofstream f;
    public:

    LogFileV4(){
        f.open("log.txt");
    } 

    void shared_print_exceptionSafe1(string sender, int info){
        lock( m_me_1, m_me_2);
        lock_guard<mutex> locker1{m_me_1, adopt_lock};
        lock_guard<mutex> locker2{m_me_2, adopt_lock};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        lock( m_me_1, m_me_2);
        lock_guard<mutex> locker2{m_me_2, adopt_lock};
        lock_guard<mutex> locker1{m_me_1, adopt_lock};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    ~LogFileV4(){
        f.close();
    }
};

void function_11(LogFileV4& log){
    for( int i=0; i>-10000; i--){
        log.shared_print_exceptionSafe2( string("from function_11: "), i);
    }
}

class LogFileV5{
    mutex m_me_1;
    ofstream f;
    public:

    LogFileV5(){
        f.open("log.txt");
        // do we to keep it open on construction
        // OR
        // open only when first used?
    } 

    void shared_print_exceptionSafe1(string sender, int info){
        //lock_guard<mutex> locker1{m_me_1, adopt_lock};
        unique_lock<mutex> locker1{m_me_1};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
        locker1.unlock();
        // you can have code to do something else that 
        // do not require mutex
        cout << "LogFileV5: threadId: " << this_thread::get_id() << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        unique_lock<mutex> locker1{m_me_1, defer_lock};
        // lock only when needed
        locker1.lock();
        f << "thread id: " << this_thread::get_id() << newLine;
        locker1.unlock();

        cout << "unlocked threadId: " << this_thread::get_id() << newLine;
        // we can do something else here

        locker1.lock();
        f << sender << " " << info << newLine;
        locker1.unlock();

        unique_lock<mutex> locker2;
        locker2 = move( locker1 ); // locker1 no longer accessible
        locker2.lock();
        f << sender << " locker2 " << info << newLine;
        locker2.unlock();
    }

    ~LogFileV5(){
        f.close();
    }
};

void function_12(LogFileV5& log){
    for( int i=0; i>-10; i--){
        log.shared_print_exceptionSafe2( string("from function_11: "), i );
    }
}

class LogFileV6{

    mutex m_me_1; // use to control writing to file
    mutex m_me_2; // used to ensure only one file is opened
    once_flag fileOpenFlag;
    ofstream f;
    public:

    void shared_print_exceptionSafe1(string sender, int info){
       /* 
        {
            unique_lock<mutex> locker2{m_me_2}; // everytime -- check mutex and check if file is opened -- this is extra useless mutex
            if(! f.is_open() ){
                //unique_lock<mutex> locker2{m_me_2}; // it is not thread safe as two threads might try to open same file twice
                f.open("log1.txt")
            }
        }
        // SOLUTION -- use once_flag
        */

        call_once( fileOpenFlag, [&](){ f.open("log1.txt"); });
        unique_lock<mutex> locker1{m_me_1};
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
    }

    void shared_print_exceptionSafe2(string sender, int info){
        call_once( fileOpenFlag, [&](){ f.open("log1.txt"); });
        unique_lock<mutex> locker1{m_me_1, defer_lock};
        locker1.lock();
        f << "thread id: " << this_thread::get_id() << newLine;
        f << sender << " " << info << newLine;
        locker1.unlock();
    }

    ~LogFileV6(){}
};

void function_13(LogFileV6& log){
    for( int i=0; i>-10; i--){
        log.shared_print_exceptionSafe2( string("from function_11: "), i );
    }
}

mutex t6Mutex;
deque<int> t6Queue;
condition_variable t6Cond;

void function_14(){ // producer
    int count{10};
    // inefficient
    /*
    while( count > 0 ){
        unique_lock<mutex> t6Locker{t6Mutex};
        t6Queue.push_front( count );
        t6Locker.unlock();
        this_thread::sleep_for( chrono::seconds(1) );
        count--;
    }
    */
    // SOLUTION : Use Condition Variables
    while( count > 0 ){
        unique_lock<mutex> t6Locker{t6Mutex};
        t6Queue.push_front( count );
        t6Locker.unlock();
        cout << "t1 pushed " << count << newLine;
        t6Cond.notify_one(); // Notify one waiting thread, if there is one
        //t6Cond.notify_all(); // Notify all waiting thread
        this_thread::sleep_for( chrono::seconds(1) );
        count--;
    }
}

void function_15(){ // consumer
    int data = 0;
    // inefficient way
    /*
       while( data != 1 ){
       unique_lock<mutex> t6Locker{t6Mutex};
       if( ! t6Queue.empty() ){
       data=t6Queue.back();
       t6Queue.pop_back();
       t6Locker.unlock();
       cout << "t2 got a value from t1: " << data << newLine;
       }
       else{
       t6Locker.unlock();
       }
       }
       */
    // SOLUTION 1: add waiting time but how much??
    /*
       while( data != 1 ){
       unique_lock<mutex> t6Locker{t6Mutex};
       if( ! t6Queue.empty() ){
       data=t6Queue.back();
       t6Queue.pop_back();
       t6Locker.unlock();
       cout << "t2 got a value from t1: " << data << newLine;
       }
       else{
       t6Locker.unlock();
       this_thread::sleep_for( chrono::milliseconds(10) );
       }
       }
       */
    // SOLUTION 2: Use Condition Variables
    while( data != 1 ){
        cout << "t2 before lock" << newLine;
        unique_lock<mutex> t6Locker{t6Mutex};
        cout << "t2 before wait" << newLine;
        t6Cond.wait( t6Locker ); // thread sleeps; wait will unlock the mutex when sleeping -- faced an issue
        //t6Cond.wait( t6Locker, [](){ return !t6Queue.empty(); } ); // spurious wake 
        data=t6Queue.back();
        t6Queue.pop_back();
        t6Locker.unlock();
        cout << "t2 got a value from t1: " << data << newLine;
    }
}

void factorial_1(int number){
    int result=1;
    for(int i=number; i>1; i--){
        result *= i;
    }
    cout << "[factorial_1] The factorial of " << number << " is " << result << newLine;
}

void factorial_2(int number, int &retResult){
    int result=1;
    for(int i=number; i>1; i--){
        result *= i;
    }
    retResult = result;
    cout << "[factorial_2] The factorial of " << number << " is " << result << newLine;
}

int factorial_3( int number ){
    int result=1;
    for(int i=number; i>1; i--){
        result *= i;
    }
    cout << "[factorial_3] The factorial of " << number << " is " << result << newLine;
    return result;
}

int factorial_4( future<int>& future ){
    int result=1;
    int number = future.get(); // exception: std::future_errc::broken_promise
    for(int i=number; i>1; i--){
        result *= i;
    }
    cout << "[factorial_4] The factorial of " << number << " is " << result << newLine;
    return result;
}

int factorial_5( shared_future<int> future ){
    int result=1;
    int number = future.get(); // exception: std::future_errc::broken_promise
    for(int i=number; i>1; i--){
        result *= i;
    }
    cout << "[factorial_5] The factorial of " << number << " is " << result << newLine;
    return result;
}

class A{
    public:

        int id;

        A():id{108}{}

        void f(int x, char c){
            this_thread::sleep_for(chrono::seconds(1));
            cout << "A voidIntChar " << x << " " << c << " id:" << id << newLine;
        }

        long g(double x){ 
            cout << "A longDouble " << x << newLine;
            return 0; 
        }

        void operator()(int n){
            cout << "A operator() " << n << newLine;
        }

};

template <typename T>
void cube(T x){
    cout << "Cube is " << x*x*x << newLine;
}

int factorial_6(int number){
    int result=1;
    for(int i=number; i>1; i--){
        result *= i;
    }
    cout << "[factorial_6] The factorial of " << number << " is " << result << newLine;
    return result;
}

condition_variable t9Cond;
mutex t9Mutex;
deque<packaged_task<int()>> taskQue;

void thread_1(){
    packaged_task<int()> t;
    {
        unique_lock<mutex> locker{t9Mutex};
        t9Cond.wait(locker, [](){ return !taskQue.empty(); });
        t = move( taskQue.front() );
        taskQue.pop_front();
    }
    t();
}


