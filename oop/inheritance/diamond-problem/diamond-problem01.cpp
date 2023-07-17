#include <iostream>
using namespace std;

class A
{
    int x{};

public:

    A(int i=7):x{i} // default ctor cum parametrized ctor
    {
        cout << "A(int) ctor" << endl;
    }

    void setX(int i)
    {
        cout << "A.i is " << i << endl;
        x = i;
    }

    int getX()
    {
        return x;
    }

    void print()
    {
        cout << x << endl;
    }

    ~A()
    {
        cout << "A dtor" << endl;
    }
};

class B : virtual public A
{
public:
    B()
    {
        cout << "B ctor" << endl;
        setX(10); // if this function not called then default value is set
    }

    ~B()
    {
        cout << "B dtor" << endl;
    }
};

class C : virtual public A
{
public:
    C()
    {
        cout << "C ctor" << endl;
        setX(20); // if this function not called then default value is set
    }

    ~C()
    {
        cout << "C dtor" << endl;
    }
};

// class D: public C, public B // order matters; output: 10
class D : public B, public C // order matters; A ctor >> B ctor >> C ctor; output: 20 (from C)
{
};

int main()
{
    {
        D d;
        d.print();
        cout << "main fn:: d.x = " << d.getX() << endl;
    }

    {
        A a;
        a.print();
        cout << "main fn:: 1 a.x = " << a.getX() << endl;
    }

    {
        A a(18);
        a.print();
        cout << "main fn:: 2 a.x = " << a.getX() << endl;
    }

    {
        A *p = new A(27);
        p->print();
        delete p;
    }
    
    return EXIT_SUCCESS;
}