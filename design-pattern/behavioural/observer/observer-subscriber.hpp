#pragma once
#include <iostream>
using namespace std;

struct subscriber{
    virtual void update() = 0; 
    virtual string getName() = 0;
};
