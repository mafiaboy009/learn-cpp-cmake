#include<iostream>
using namespace std;

class A
{
    int x{};

    public:

    void setX(int i) {
        cout << "A.i is " << i << endl; 
        x = i; 
    }

    void print() { 
        cout << x << endl; 
    }
};

class B: virtual public A
{
    public:
        B() { 
            cout << "B" << endl; 
            setX(10); // if this function not called then default value is set
        }
};

class C: virtual public A
{
    public:
        C() { 
            cout << "C" << endl; 
            setX(20); // if this function not called then default value is set
        }
};

//class D: public B, public C { // order matters; output: 20
class D: public C, public B { // order matters; output: 10
};

int main()
{
    D d;
    d.print();
    return 0;
}
