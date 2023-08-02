#pragma once

template <typename T>
class singly_node final
{
private:
    T _data{};
    singly_node<T>* _nextNode{nullptr};

public:
    singly_node() : _data{}, _nextNode{} {}
    singly_node(T inData) : _data{inData}, _nextNode{nullptr} {}
    singly_node<T>* getNextNode();
    void setNextNode(singly_node<T> *nextNode);
    T getData();
};

//#include "node.cpp"