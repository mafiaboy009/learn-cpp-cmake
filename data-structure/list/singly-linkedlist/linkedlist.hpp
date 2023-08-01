#pragma once
#include "node.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class linkedList final
{
private:
    node<T> *_head{nullptr};
    unsigned _length{};

public:
    linkedList() : _head{nullptr}, _length{0} {}
    void insert(T inData);
    void findData(T inData, vector<unsigned> &index);
    void remove(unsigned i);
    void removeData(T inData);
    void removeDuplicates(T inData);
    void reverse();
    void print();
    void clear();
    node<T>* getHead();
    ~linkedList();
};

//#include "linkedlist.cpp"