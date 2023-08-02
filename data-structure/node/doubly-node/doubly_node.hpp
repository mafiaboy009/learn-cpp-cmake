#pragma once

template <typename T>
class doubly_node final
{
private:
    T _data{};
    doubly_node<T>* _nextNode{nullptr};
    doubly_node<T>* _prevNode{nullptr};

public:
    doubly_node() : _data{}, _nextNode{}, _prevNode{} {}
    doubly_node(T inData) : _data{inData}, _nextNode{nullptr}, _prevNode{nullptr} {}
    doubly_node<T>* getNextNode();
    doubly_node<T>* getPrevNode();
    void setNextNode(doubly_node<T> *nextNode);
    void setPrevNode(doubly_node<T> *nextNode);
    T getData();
};