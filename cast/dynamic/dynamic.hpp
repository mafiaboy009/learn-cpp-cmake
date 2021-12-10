#pragma once

#include <iostream>

using namespace std;

class dog{
    public:
        virtual ~dog() {}
};

class yellowdog: public dog {
    public:
    int age;

    // the following member function do not use/have 
    // data members and it is similar to a static member function
    // if the function uses a data member then segmentation
    // fault will happen
    void bark(){
        cout << " yellow woof !\n";
    }
};
