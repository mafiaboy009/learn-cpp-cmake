#include <iostream>

class A final{
    public:
    int a{};
    private:
    protected:
};

/* class B: public A{ // not possible since A is final class
    public:
    int b{};
    private:
    protected:
}; */

int main(){
//     B b;
    A a;

    return EXIT_SUCCESS;
}