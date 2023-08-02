#pragma once
#include "doubly_node.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class doublyLinkedList{
    doubly_node<T> *head{};
    doubly_node<T> *tail{};
    unsigned _length{};
public:
    doublyLinkedList():head{nullptr},tail{nullptr}{}
    void push_front(T data);
    void push_back(T data);
    void display();
    void reverseDisplay();
    void deleteNode( int position );
    void clear( );
    ~doublyLinkedList();
};

