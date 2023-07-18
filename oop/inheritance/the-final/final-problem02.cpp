/*
Sometimes you don’t want to allow derived class to override the base class’ virtual function
*/

#include <iostream>
using namespace std;
 
class Base
{
public:
    virtual void myfun() final
    {
        cout << "myfun() in Base";
    }
};

class Derived : public Base
{
/* 
    //uncommenting this block will result in compilation error
    void myfun()
    {
        cout << "myfun() in Derived\n";
    } */
};
 
int main()
{
    Derived d;
    Base &b = d;
    b.myfun();
    return EXIT_SUCCESS;
}