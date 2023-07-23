#pragma once

template <typename T>
class node final
{
private:
    T _data{};
    node<T>* _nextNode{nullptr};

public:
    node() : _data{}, _nextNode{} {}
    node(T inData) : _data{inData}, _nextNode{nullptr} {}
    node<T>* getNextNode();
    void setNextNode(node<T> *nextNode);
    T getData();
};

#include "node.cpp"