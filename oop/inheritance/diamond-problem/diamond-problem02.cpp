#include<iostream>
using namespace std;

class A
{
    int x;

    public:

    A():x{4}{ cout << "A ctor" << endl; }

    A(int i):x{i}{}

    void print() { 
        cout << x << '\n'; 
    }

    ~A(){ cout << "A dtor" << endl; }
};

class B: virtual public A
{
    public:
        B():A(10) { cout << "B ctor" << endl; } // default constructor of A called
        ~B(){ cout << "B dtor" << endl; }
};

class C: virtual public A
{
    public:
        C():A(11) { cout << "C ctor" << endl; } // default constructor of A called
        ~C(){ cout << "C dtor" << endl; }
};

class D: public B, public C {
    public:
    D(){ cout << "D ctor" << endl; }
    ~D(){ cout << "D dtor" << endl; }
};

int main()
{
    D d; // default constructor of A called
    d.print();
    return 0;
}
