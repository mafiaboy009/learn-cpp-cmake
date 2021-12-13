#include<iostream>
using namespace std;

class A
{
    int x;

    public:

    A():x{4}{}

    A(int i){ 
        x = i; 
    }

    void print() { 
        cout << x << '\n'; 
    }
};

class B: virtual public A
{
    public:
        B():A(10) { } // default constructor of A called
};

class C: virtual public A
{
    public:
        C():A(11) { } // default constructor of A called
};

class D: public B, public C {
};

int main()
{
    D d; // default constructor of A called
    d.print();
    return 0;
}
