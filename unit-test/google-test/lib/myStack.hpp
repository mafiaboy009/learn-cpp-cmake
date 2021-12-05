#pragma once

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

const char newLine = '\n';

class MyStack{
    vector<int> _stack;
    int _sp;
  public:
    MyStack();
    ~MyStack(){};

    void push(int);
    void pop();
    int top();
    string toString();
};
