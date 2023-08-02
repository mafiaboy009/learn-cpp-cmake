#include "singly_node.hpp"

template <typename T>
singly_node<T>* singly_node<T>::getNextNode()
{
    return _nextNode;
}

template <typename T>
void singly_node<T>::setNextNode(singly_node<T>* nextNode)
{
    _nextNode = nextNode;
}

template <typename T>
T singly_node<T>::getData()
{
    return _data;
}