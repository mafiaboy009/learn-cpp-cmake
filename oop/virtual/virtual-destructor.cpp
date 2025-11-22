/*
* Note:
* 1. if your class has at least one virtual function, you should declare a virtual destructor to ensure proper cleanup of derived class objects.
* 2. If a base class destructor is not virtual, deleting a derived class object through a base class pointer results in undefined behavior.
* 3. Always declare destructors as virtual in base classes when you expect to derive from them.
*/

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base dtor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived dtor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Correctly calls Derived's destructor followed by Base's destructor
    return 0;
}

