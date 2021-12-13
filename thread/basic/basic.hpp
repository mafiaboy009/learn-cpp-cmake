#include <iostream>
#include <thread>

using namespace std;

const char newLine = '\n';

void function_1(){
    cout << "Beauty is only skin-deep\n";
}

void function_2(){
    for( int i=0; i>-3; i--){
        cout << "from function_2: " << i << newLine;
    }
}

class Functor1{
    public:
        void operator()(){
            for( int i=0; i>-3; i--){
                cout << "from Functor1: " << i << newLine;
            }
        }
};

class Functor2{
    public:
        void operator()(string msg){
            cout << "Functor2 says: " << msg << newLine;
        }
};

class Functor3{
    public:
        void operator()(string& msg){
            cout << "Functor3 says: " << msg << newLine;
            msg = "Trust in the mother of deceit";
            cout << "Functor3 says: " << msg << newLine;
        }
};
